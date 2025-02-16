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

ll helper(ll n)
{
    string s = to_string(n);
    string ans;

    int cnt = 0;
    for (char c : s)
    {
        if (c == '3')
        {
            cnt++;
        }
        else
        {
            if (cnt % 2 != 0)
            {

                ans.append(cnt, '3');
            }
            cnt = 0;
            ans += c;
        }
    }

    if (cnt % 2 != 0)
    {
        ans.append(cnt, '3');
    }

    return ans.empty() ? 0 : stoll(ans);
}
void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll n;
        cin >> n;
        bool fg = true;
        while (n > 0)
        {
            n = helper(n);
            if (n > 0)
            {
                n -= 33;
            }
            if (n == 0)
                break;
            if (n < 0)
            {
                fg = false;
                break;
            }
        }
        if (fg)
        {
            cout << "YES" br;
        }
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
