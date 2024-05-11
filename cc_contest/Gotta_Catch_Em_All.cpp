#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll a[n];
        ll s = 0;
        rep(i, n)
        {
            cin >> a[i];
            s += (x * a[i]);
        }
        ll ans = s;
        sort(a, a + n);

        for (ll i = n - 1; i >= 0; i--)
        {
            s -= (x * a[i]);
            s += y;
            ans = min(ans, s);
        }
        cout << ans br;
    }

    return 0;
}