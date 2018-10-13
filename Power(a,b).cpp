#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<pr> vp;
typedef vector<vp> vpp;
typedef vector<vector<ll> > graph;
#define pb push_back
#define mp make_pair
#define maxi INT_MAX
#define mini INT_MIN
ll mod = pow(10,9) + 7;

ll power(ll a,ll b)
{
    if(b==0)
    return 1;
    ll temp = power(a,b/2);
    if(b%2==0)
    return (temp*temp)%mod;
    return (((temp*temp)%mod)*a)%mod;
    
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<power(a,b)<<endl;
    }
}