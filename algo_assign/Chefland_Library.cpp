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

ll fact(ll n)
{
    if (n == 1 || n == 0)
        return 1;
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
        ans *= i;
    return ans;
}
// jo cheating kiya, uski ma r****

void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n + 1, 0);
        rep(i, n)
        {
            ll temp;
            cin >> temp;
            a[temp] = max(a[temp], i + 1);
        }
        // rep(i, n + 1) cout << a[i] << " ";
        ll ans = 0;
        rep(i, n + 1)
        {
            ans += a[i];
        }
        cout << ans br;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
