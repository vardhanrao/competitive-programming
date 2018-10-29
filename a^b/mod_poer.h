
// BY hg398 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define mo 1000000007

ll mod_poer(ll a,ll b)
{
	ll res=1; 
	while(b>0) 
	{ 
		if(b&1) 
		res=(res*a)%mo;
		a=(a*a)%mo;
		b/=2;
	} 
	return res%mo;
}

int main() {
	boost;
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<mod_poer(a,b);
	}
	return 0;
}