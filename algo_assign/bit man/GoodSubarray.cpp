#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        ll ans = 0;
        ll curr = 0;
        unordered_map<ll, ll> ump;
        ump[0]=1;
        rep(i, 0, n)
        {
            curr ^= a[i];
            ans = (ans + ump[curr]++) % mod;
        }
        cout << ans br;
    }
}