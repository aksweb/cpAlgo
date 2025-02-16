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
        ll t, p;
        cin >> t >> p;
        ll x = (1000 - p + 20 * t) / 21;
        cout << min(300 - t - 1, x - t) br;
    }

    return 0;
}