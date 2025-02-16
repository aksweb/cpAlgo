
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

//submitting in practice: WA aya tha cnt me
void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll n;
        cin >> n;

        ll l, r;
        cin >> l >> r;

        vector<ll> v(n);
        rep(i, n) cin >> v[i];

        unordered_map<ll, ll> mp;
        bool flg = false;

        rep(i, n)
        {
            mp[v[i]]++;
            if (mp[v[i]] > 1)
            {
                flg = true;
                break;
            }
        }

        if (flg)
        {
            if (0 >= l && 0 <= r)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }

        ll p = 1;
        bool overflow = false;

        for (ll i = 0; i < n - 1; ++i)
        {
            for (ll j = i + 1; j < n; ++j)
            {
                p *= (v[i] ^ v[j]);

                if (p == 0)
                {
                    overflow = true;
                    break;
                }
                if (p > r)
                {
                    overflow = true;
                    break;
                }
            }
            if (overflow)
                break;
        }

        if (p >= l && p <= r)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
