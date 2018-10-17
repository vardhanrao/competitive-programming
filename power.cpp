#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{int t,a,b,A[100],i=0,ind;
cin>>t;ind=t;
cout<<endl;

do
{
cin>>a>>b;
cout<<endl;
A[i]=pow(a,b);
i++;
t--;
}
while(t!=0);

for(i=0;i<ind;i++)
{cout<<A[i]<<endl;
}

return 0;
}
