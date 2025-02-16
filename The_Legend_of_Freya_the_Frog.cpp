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
    ll _;
    cin >> _;
    while (_--)
    {
        ll x, y, d;
        cin >> x >> y >> d;
        ll movx = static_cast<ll>(ceil((x * 1.0) / d));
        ll movy = static_cast<ll>(ceil((y * 1.0) / d));
        if (movy >= movx)
            cout << 2 * movy br;
        else
            cout << (2 * movx) - 1 br;
    }

    return 0;
}