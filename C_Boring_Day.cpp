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
        ll n, l, r;
        cin >> n >> l >> r;

        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];

        ll ans = 0;
        ll sum = 0;
        ll lt = 0;

        for (ll rt = 0; rt < n; rt++)
        {
            sum += v[rt];
            while (sum > r && lt <= rt)
            {
                sum -= v[lt];
                lt++;
            }
            if (sum >= l && sum <= r)
            {
                ans++;
                sum = 0;
                lt = rt + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
