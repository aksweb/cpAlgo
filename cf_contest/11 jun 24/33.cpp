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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }

        ll sum = 0;
        int ans = 0;
        ll mx = 0;

        rep(i, 0, n)
        {
            sum += a[i];
            mx = max(mx, a[i]);
            if (mx == sum - mx)
            {
                ans++;
            }
        }

        cout << ans br;
    }

    return 0;
}
