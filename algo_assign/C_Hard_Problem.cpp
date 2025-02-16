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
#define rloop(i, a, b) for (ll i = a; i > b; i--)
#define trav(a, b) for (auto a : b)
#define MOD2 629421302
#define INF 1000000000000000000

// Ye kab tk likhoge
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// jo cheating kiya, uski ma r****

void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        ll r1 = 0, r2 = 0;
        r1 = min(a, m);
        r2 = min(b, m);
        // cout << "R: " << r1 << " " << r2 br;
        ll rem = (2 * m) - r1 - r2;
        // cout << "rem: " << rem br;
        if (rem >= c)
            cout << r1 + r2 + c br;
        else
        {
            cout << 2 * m br;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
