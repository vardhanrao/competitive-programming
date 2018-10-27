#include <bits/stdc++.h>
using namespace std;
void multiply(long long int a[2][2],long long int b[2][2],int mod)
{
    long long int mul[2][2];
    mul[0][1]=((a[0][0]*b[1][0]+a[0][1]*b[1][1])%mod);
    mul[0][0]=((a[0][0]*b[0][0]+a[0][1]*b[0][1])%mod);
    mul[1][0]=((a[1][0]*b[0][0]+a[1][1]*b[0][1])%mod);
    mul[1][1]=((a[1][0]*b[1][0]+a[1][1]*b[1][1])%mod);
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            a[i][j] = mul[i][j];
}
void power(long long int F[2][2], int n,int mod)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{0,1},{1,1}};
  power(F, n/2,mod);
  multiply(F, F,mod);
  if (n%2 != 0)
     multiply(F, M,mod);
}
int fibonacci_of_n(int n,int mod){
      long long int a[2][2]={{0,1},{1,1}};
      power(a,n,mod);
    return a[1][1];
}

int main() {
    int n;  
    cin>>n;
    int temp;
    for(int i = 0; i <= n; i++)
    {
         cin>>temp;
         cout<<fibonacci_of_n(temp,1000000007);
    }
    return 0;
}