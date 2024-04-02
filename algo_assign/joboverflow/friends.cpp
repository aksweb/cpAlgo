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

// question rd k l
// constraits
// consider tc
// isse achha approach nhi melega bhai.

// Ye kab tk likhoge
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int pred(ll m, vector<ll> &v, ll p)
{
    ll n = v.size();
    ll pf = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i + 1] - v[i] <= m)
        {
            pf++;
            i++;
        }
        if (pf >= p)
            return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll n, p;
        cin >> n >> p;
        vector<ll> v(n);
        rep(i, n) cin >> v[i];
        sort(v.begin(), v.end());

        ll l = -1, r = v[n - 1] - v[0];
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (pred(m, v, p) == 0)
                l = m;
            else
                r = m;
        }
        cout << r br;
    }

    return 0;
}
