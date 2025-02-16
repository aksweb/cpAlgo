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

ll fact(ll n)
{
    if (n == 1 || n == 0)
        return 1;
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
        ans *= i;
    return ans;
}
bool isDivisibleBy7(ll d, ll n)
{
    // Calculate n!
    ll nFact = fact(n);

    // If n! >= 7, the repeated number modulo 7 becomes 0
    if (nFact >= 7)
    {
        return (d % 7 == 0); // Only check divisibility of d
    }

    // If n! < 7, calculate full modulo
    ll repeatedOnesModulo7 = (1 * (fact(n) % 7)) % 7;
    ll result = (d % 7) * repeatedOnesModulo7 % 7;

    return (result == 0);
}

void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll n, d;
        cin >> n >> d;
        cout << "1 ";
        if (n > 2 || d % 3 == 0)
            cout << "3 ";
        if (d == 5)
            cout << "5 ";
        if (n > 2 || d == 7)
            cout << "7 ";
        if ((d == 9) || (n > 2) && d % 3 == 0 || n >= 6)
            cout << "9 ";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
