// TESTEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _;
    cin >> _;
    while (_--)
    {

        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll max_cnt = 0;
        ll ans = 0;
        ll mx = a[0];
        for (int i = 1; i < n; i++)
        {
            if (mx > a[i])
            {
                ans += mx - a[i];
                max_cnt = max(max_cnt, mx - a[i]);
            }
            mx = max(mx, a[i]);
        }
        cout << ans + max_cnt br;
    }
    return 0;
}
