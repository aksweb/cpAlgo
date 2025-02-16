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

void solve()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll ans = 0;

        // Iterate over possible powers of k^n
        ll power_k = 1; // k^0 = 1 initially
        while (true)
        {
            // Calculate the valid range for x
            ll x_min = max(l1, (l2 + power_k - 1) / power_k); // Ceil division for l2 / k^n
            ll x_max = min(r1, r2 / power_k);                 // Floor division for r2 / k^n

            if (x_min > x_max)
            {
                break; // No valid x in this range
            }
            // tab shanti me gutan hui, aur mara ye santi me 

            // Add all valid x values for this power of k
            ans += (x_max - x_min + 1);

            // Prevent overflow for the next power of k
            if (power_k > r2 / k)
            {
                break;
            }
            power_k *= k;
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

// // Ye kab tk likhoge
// ll gcd(ll a, ll b)
// {
//     return (b == 0) ? a : gcd(b, a % b);
// }
// ll lcm(ll a, ll b)
// {
//     return a * (b / gcd(a, b));
// }

// // jo cheating kiya, uski ma r****

// void solve()
// {
//     ll _;
//     cin >> _;

//     while (_--)
//     {
//         ll k, l1, r1, l2, r2;
//         cin >> k >> l1 >> r1 >> l2 >> r2;
//         ll ans = 0;
//         ll st1 = l2 / k, end1 = r2 / k;
//         st1 = min(r1, st1);
//         end1 = min(end1, r1);
//         cout << st1 << " : " << end1 br;
//         ll range1 = end1 - st1;
//         cout << range1 br;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     solve();

//     return 0;
// }
