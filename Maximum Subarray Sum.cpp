#include <iostream>
#define ll long long
using namespace std;

void maxSubarraySum(ll *a, ll n)
{
    ll maxsum = 0;
    ll currentsum = 0;
    ll s = -1, e = -1, temp = 0;
    for(ll i = 0; i < n; i++)
    {
        currentsum += a[i];
        if(currentsum > maxsum)
        {
            maxsum = currentsum;
            s = temp;
            e = i;
        }
        if(currentsum < 0)
        {
            currentsum = 0;
            temp = i + 1;
        }
    }
    cout << maxsum << " " << s << " " << e << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        maxSubarraySum(a, n);
    }
}
