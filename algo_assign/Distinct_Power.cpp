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

bool check(vector<ll> &a, ll m)
{
    ll n = a.size();
    set<vector<ll>> st;
    rep(i, n)
    {
        ll tmp = a[i];
        vector<ll> v;
        rep(j, n)
        {
            if (a[j] != tmp)
            {
                if (a[j] > tmp)
                {
                    v.push_back(a[j] - 1);
                }
                else
                    v.push_back(a[j]);
            }
        }
        st.insert(v);
    }
    if (st.size() >= m)
        return true;
    return false;
}
void solve()
{
    ll _;
    cin >> _;

    while (_--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        rep(i, n)
        {
            cin >> a[i];
        }
        
        vector<ll> b(a.begin(), a.end());
        sort(b.begin(), b.end());
        unordered_map<ll, ll> mp;
        ll rank = n;
        rep(i, n)
        {
            mp[b[i]] = rank--;
        }
        rep(i, n)
        {
            a[i] = mp[a[i]];
        }
        // rep(i, n) cout << a[i] << " ";
        // cout << endl;
        // apply binary search here
        ll l = 1, h = n;
        ll ans = 1;
        while (l <= h)
        {
            ll m = l + (h - l) / 2;
            if (check(a, m))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
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
