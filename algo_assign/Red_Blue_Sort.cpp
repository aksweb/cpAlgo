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
    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        vector<ll> vect(n);
        for (auto &x : vect)
            cin >> x;
        vector<bool> vis(n + 1, false);
        ll k = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ll num = 0;
                ll l = i;
                while (!vis[l])
                {
                    vis[l] = 1;
                    l = vect[l - 1];
                    num++;
                }
                if (num >= 2)
                    k += num;
            }
        }
        if (k == 0)
        {
            cout << n br;
        }
        else if (k <= n - 1)
        {
            cout << n - 1 br;
        }
        else
        {
            cout << n - 2 br;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}