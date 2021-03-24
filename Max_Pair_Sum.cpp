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

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n], b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        ll pos[n];
        for(int i=0;i<n;i++)
        pos[i]=n-1;
        priority_queue<pr> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(mp(a[i]+b[n-1], i));
        }
        while(k--)
        {
            ll temp = pq.top().first;
            ll index = pq.top().second;
            pq.pop();
            if(pos[index]>0)
            {
                pos[index]--;
                pq.push(mp(a[index]+b[pos[index]],index));
            }
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    
    
}