
// A simple C++ program to find N maximum 
// combinations from two arrays, 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to display first N maximum sum 
// combinations 
void NMaxCombinations(int A[], int B[], int N, 
                                        int K) 
{ 
    // max heap. 
    priority_queue<int> pq; 
  
    // insert all the possible combinations  
    // in max heap. 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            pq.push(A[i] + B[j]); 
  
    // pop first N elements from max heap 
    // and display them. 
    int count = 0; 
    while (count < K) { 
        cout << pq.top() << endl; 
        pq.pop(); 
        count++; 
    } 
} 
  
// Driver Code. 
int main() 
{ 
    int A[] = { 4, 2, 5, 1 }; 
    int B[] = { 8, 0, 5, 3 }; 
    int N = sizeof(A)/sizeof(A[0]); 
    int K = 3; 
    NMaxCombinations(A, B, N, K); 
    return 0; 
} 
