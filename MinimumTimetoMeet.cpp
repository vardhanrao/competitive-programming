
// C++ program to find minimum time 
// required to produce m items. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Return the minimum time required to 
// produce m items with given machines. 
int minTime(int arr[], int n, int m) 
{ 
    // Intialise time, items equal to 0. 
    int t = 0; 
  
    while (1) 
    { 
        int items = 0; 
  
        // Calculating items at each second 
        for (int i = 0; i < n; i++) 
            items += (t / arr[i]); 
  
        // If items equal to m return time. 
        if (items >= m) 
            return t; 
  
        t++; // Increment time 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 1, 2, 3 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int m = 11; 
  
    cout << minTime(arr, n, m) << endl; 
  
    return 0; 
} 
