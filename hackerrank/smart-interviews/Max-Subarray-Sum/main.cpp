#include<iostream> 
#include<climits> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, start =0, end = 0, s=0; 
    for (int i=0; i < size; i++) { 
        max_ending_here += a[i]; 
        if (max_so_far < max_ending_here) { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
        if (max_ending_here < 0){ 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    cout << max_so_far << ' ' << start << ' ' << end << endl; 
} 
  
int main() 
{ 
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    int ar[N];
	    for(int i = 0 ; i < N ; ++i) cin >> ar[i];
	    int max_sum = maxSubArraySum(ar, N); 
	}
    return 0; 
} 
