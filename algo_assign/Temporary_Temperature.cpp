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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &x : a)
            cin >> x;
        ll mini = a[0], maxi = a[0];
        for (ll &x : a)
        {
            if (x < mini)
                mini = x;
            if (x > maxi)
                maxi = x;
        }

        ll left = 0, right = (ll)(maxi) - (ll)(mini);
        if (right < 0)
        {
            right = 0;
        }

        while (left < right)
        {
            ll m = left + (right - left) / 2;
            ll letsCountIt = 1;
            ll low = (ll)a[0] - m;
            ll h = (ll)a[0] + m;
            // applying...

            repi(i, n - 1)
            {
                ll nl = (ll)a[i] - m;
                ll n_hg = (ll)a[i] + m;
                low = max(low, nl);
                h = min(h, n_hg);
                if (low > h)
                {
                    letsCountIt += 1;
                    low = nl;
                    h = n_hg;
                }
            }
            if (letsCountIt <= (ll)(k) + 1)
            {
                right = m;
            }
            else
            {
                left = m + 1;
            }
        }
        cout << left br;
    }
}