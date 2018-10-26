 # include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
      int n,k;
      cin>>n>>k;
      int r=n*n;
      int a[n],b[n],s[r];
      for(int i=0;i<n;i++)
      {
          cin>>a[i];
      }
       for(int i=0;i<n;i++)
      {
          cin>>b[i];
      }
      int l=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {
              s[l]=a[i]+b[j];
              l++;
          }
      }
     sort(s,s+r);
     for(int i=r-1;i>=r-k;i--)
     {
         cout<<s[i]<<" ";
     }
     cout<<endl;
  }
}
