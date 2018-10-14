#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k,i;
		cin>>n>>k;
		long long a[n], b[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		sort(a, a+n, greater<int>());
		sort(b, b+n, greater<int>());
		i=0;
		long long j=0, x=0;
		while(x<k)
		{
			cout<<a[i]+b[j]<<" ";
			if(b[j+1]<a[i])
			{
				j++;
			}
			else
			{
				i++;
			}
			x++;
		}
		cout<<endl;
	}
}
