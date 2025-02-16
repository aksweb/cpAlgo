// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

void solve()
{
    ll _;
    cin >> _;
    while (_--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n];
        rep(i, n) cin >> a[i];
        ll ans = 0;
        rep(i, m)
        {
            ll x;
            cin >> x;
            if (a[x - 1]-- <= 0)
                ans++;
        }
        cout << ans br;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
