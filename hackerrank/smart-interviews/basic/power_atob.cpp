// Find Factors of a Number

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// compute a^b in O(logn)
long long int power(long long int a, long long int b)
{
    if(b == 0) return 1;
    
    long long int temp = power(a, b/2);
    if(b % 2 == 0) {
        return ((temp%MOD)*(temp%MOD))%MOD;
    }
    return ((a%MOD)*(((temp%MOD)*(temp%MOD))%MOD))%MOD;
}

int main() {
    
    int t;
    long long int a, b;
    
    cin >> t;   // number of queries
    while(t--) {
        cin >> a >> b; // get the value of a and b
        
        cout << power(a,b) << endl;
    }

    return 0;
}