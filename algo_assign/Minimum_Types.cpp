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

// jo cheating kiya, uski ___
void solve()
{
    int _;
    cin >> _;

    while (_--)
    {
        ll n, x;
        cin >> n >> x;
        ll a[n], b[n];
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        if (x == 0)
        {
            cout << 0 br;
            continue;
        }
        ll total = 0;
        vector<ll> price;
        ll ans = 0;
        rep(i, n)
        {
            price.push_back(a[i] * b[i]);
        }

        sort(price.begin(), price.end());
        for (ll i = n - 1; i >= 0 && x > 0; i--)
        {
            x -= price[i];
            ans++;
        }
        if (x <= 0)
            cout << ans br;
        else
            cout << -1 br;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}