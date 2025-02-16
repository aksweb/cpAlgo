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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];

        ll totSmall = 0, totBig = 0;
        for (auto x : a)
        {
            ll smaller, gt;
            if (x >= 0)
            {
                smaller = x / k;
                gt = (x % k == 0) ? smaller : smaller + 1;
            }
            else
            {
                if (x % k == 0)
                {
                    smaller = x / k;
                    gt = smaller;
                }
                else
                {
                    smaller = x / k - 1;
                    gt = x / k;
                }
            }
            totSmall += smaller;
            totBig += gt;
        }

        if (totSmall <= 0 && totBig >= 0)
            cout << "YES" br;
        else
            cout << "NO" br;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
