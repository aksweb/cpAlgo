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

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        unordered_map<int, int> x, y;
        rep(i, n)
        {
            ll a, b;
            cin >> a >> b;
            if ((a == 0 && b == 0) || (a != 0 && b == 0))
                x[a] = -1;
            else
                y[a] = -1;
        }
        ll ans = 0;

        for (auto p : x)
        {
            if (y.find(p.first - 1) != y.end() && y.find(p.first + 1) != y.end())
            {
                ans++;
            }
            if (y.find(p.first) != y.end())
                ans += y.size() - 1;
        }
        for (auto p : y)
        {
            if (x.find(p.first - 1) != x.end() && x.find(p.first + 1) != x.end())
            {
                ans++;
            }
            if (x.find(p.first) != x.end())
                ans += x.size() - 1;
        }
        cout << ans br;
        // for (auto p : x)
        //     cout << p.first << " " << p.second << " ";
        // cout br;
        // for (auto p : y)
        //     cout << p.first << " " << p.second << " ";
    }

    return 0;
}
