// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

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
        ll a[n];
        rep(i, n) cin >> a[i];
        int mx = *max_element(a, a + n);
        ll ans = 0;
        rep(i, n)
        {
            if (a[i] == mx)
            {
                ans = max((i / 2) + ((n - i + 1) / 2) + mx, ans);
            }
        }
        cout << ans br;
    }

    return 0;
}
