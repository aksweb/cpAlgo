// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _;
    cin >> _;
    while (_--)
    {

        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        ll mn = LLONG_MAX;
        int neg = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
            if (a[i] < 0)
                neg++;
            mn = min(mn, abs(a[i]));
        }

        if (neg % 2 == 1)
        {
            sum -= 2 * mn;
        }

        cout << sum br;
    }
    return 0;
}
