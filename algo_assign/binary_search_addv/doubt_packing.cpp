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

// printing last occurence if found or just greater if not.
int pred(ll m, ll w, ll h, ll t)
{

    if (((m / w) * (m / h)) < t)
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll w, h, t;
        cin >> w >> h >> t;

        ll n = (w + h) * t;
        ll l = 0, r = n;

        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (pred(m, w, h, t) == 0)
                l = m;
            else
                r = m;
        }
        cout << r br;
    }

    return 0;
}
