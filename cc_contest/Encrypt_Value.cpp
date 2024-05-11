#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int fg = 0;

        ll ans = a[0];
        rep(i, 1, n)
        {
            if (a[i] == 1 || a[i] == 0 || (ans <= 1 && a[i] > 1))
            {
                ans = (ans + a[i]) % MOD;
            }
            else
            {
                ans = (ans * a[i]) % MOD;
            }
        }
        cout << ans br;
    }

    return 0;
}