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
    ll _;
    cin >> _;
    while (_--)
    {

        ll n, a = 0, b = 0, t = 0;

        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> t;
            if (i % 2 == 0)
                a += t; // Add to even-index sum
            else
                b += t; // Add to odd-index sum
        }
        ll g = n / 2; // Number of odd indices
        ll h = n - g; // Number of even indices

        // Check divisibility and per-index equality
        if ((a % h) || (b % g) || (a / h != b / g))
        {
            cout << "NO" br; // Not possible
        }
        else
            cout << "YES" br; // Possible
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}