


#include<stdio.h>


long power(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return power(x*x,n/2);
    else                             //n is odd
        return x*power(x*x,(n-1)/2);
}

int main(){
  int a;
  int b;
  int t;
  long ans;
  cin>>t;
  while(t--){
   cin>>a;
   cin>>b;
   ans = power(a,b);
   cout<<ans<<endl;
  }
}
