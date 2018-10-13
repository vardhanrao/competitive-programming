#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct Node
{
    unsigned int data;
    Node *left, *right;

    Node(unsigned int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

struct Tree
{
    Node *root;

    Tree()
    {
        root = NULL;
    }

    void insert(unsigned int data)
    {
        if(!root) {
            root = new Node(data);
        } else {
            Node *curr_node = root, *prev_node;

            do {
                prev_node = curr_node;
                if(data < curr_node->data) {
                    curr_node = curr_node->left;
                } else {
                    curr_node = curr_node->right;
                }
            } while (curr_node);

            if(data < prev_node->data) {
                prev_node->left = new Node(data);
            } else {
                prev_node->right = new Node(data);
            }
        }
    }

    long long get_sum() const
    {
        return recursive_sum(root, 0);
    }

    long long recursive_sum(Node *node, long long sum) const
    {
        if (!node) {
            return 0;
        }

        sum = (sum * (unsigned int)pow(10, get_num_digits(node->data)) + node->data) % MOD;

        if (!node->left && !node->right) {
            return sum;
        }

        return recursive_sum(node->left, sum) + recursive_sum(node->right, sum);
    }

    unsigned int get_num_digits (unsigned int i) const
    {
        return i > 0 ? (unsigned int) log10 ((double) i) + 1 : 1;
    }
};

int main()
{
    int T, N;
    unsigned int d;
    vector<long long> ans;
    cin>>T;

    ans.resize(T);
    for (int i=0; i<T; ++i) {
        Tree tree;
        cin>>N;

        for (int j=0; j<N; ++j) {
            cin>>d;

            tree.insert(d);
        }
        ans[i] = tree.get_sum();
    }

    for (int i=0; i<T; ++i) {
        cout<<ans[i]<<endl;
    }

    return 0;
}