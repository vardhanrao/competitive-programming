#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

/**
 * Structure for Node
 * */
struct Node
{
	int data;
	Node *left, *right;
	Node(int dd) {
		data = dd;
		left = right = NULL;
	}
};

/**
 * Construct the Binary Search Tree
 * */
Node *insertData(Node *head, int data)
{
	if(head == NULL) {
		return new Node(data);
	}

	if(head->data == data) return head;

    if(head->data > data) {
		head->left = insertData(head->left, data);
	}
	else {
	    head->right = insertData(head->right, data);
	}
	return head;
}

/**
 * Algorithm to Sum the head to leaf -> node may have multiple digit value
 * */
void traverse(Node *head, long long int *totalSum, long long int currentNum)
{
	if(head == NULL) return;
	
	// currentNum generated
	// 100 + 2 = 102 % 5 = 2 <==> 100%5 + 2%5 = 2
	// same result;
	currentNum = currentNum % MOD;

	int digits = 0;

	// Get the number of digits in the head->data
	if(head->data) {
		digits = log10(head->data) + 1;
	}

	// If the current node is the leaf node in the tree
	if(head->left == NULL && head->right == NULL) {

		//update the currentNum Value
		currentNum = ((currentNum*static_cast<int>(pow(10,digits))) + head->data % MOD) % MOD;
		
		// add the head to leaf (value generated) % MOD to the totalSum
		*totalSum = ((*totalSum)%MOD  + currentNum)%MOD;
		
		return;
	}

	// traverse the left node of the head node
	traverse(head->left, totalSum, ((currentNum*static_cast<int>(pow(10,digits))) + head->data % MOD) % MOD);
	
	// traverse the right node of the head node
	traverse(head->right, totalSum, ((currentNum*static_cast<int>(pow(10,digits))) + head->data % MOD) % MOD);
}

/**
 * Main Function Call to calculate the head-to-leaf sum total
 * */
long long int sumHeadLeft(Node *head)
{
	long long int totalSum = 0;

	if(head == NULL) return totalSum;

	traverse(head, &totalSum, 0);
	
	return totalSum;
}

int main() {

	int t;
	int n, data;

	cin >> t;
	while(t--) {

		Node *head = NULL;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> data;
			head = insertData(head, data);
		}
		cout << sumHeadLeft(head) << endl;
	}
}