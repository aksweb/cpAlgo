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
        ll n, k;
        cin >> n >> k;
        ll a[n] = {0};
        ll st = 1, end = n;
        while (st < end)
        {
            int temp = 0;

            while (temp < k - 1)
            {
                cout << end-- << " ";
                temp++;
            }
            // if (st++ != end)
            cout << st++ << " ";
        }
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

// #include <bits/stdc++.h>
// using namespace std;
// int T, n, k, cnt;
// int main()
// {
//     cin.tie(0)->sync_with_stdio(0);
//     for (cin >> T; T--;)
//     {
//         cin >> n >> k;
//         cnt = n / k;
//         for (int i = 1; i <= n; ++i)
//             cout << (i % k ? ++cnt : i / k) << " \n"[i == n];
//     }
//     return 0;
// }
