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

bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// Code Begins Here
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

bool can_rm(ll m, ll h, ll a[], ll n)
{
    ll count = 0;
    for (int i = 0; i < n; ++i)
    {
        count += ceil(static_cast<long double>(a[i]) / static_cast<long double>(m));
        if (count > h)
        {
            // cout << count br;
            return false;
        }
    }
    // cout << count br;

    return true;
}

// printing last occurence if found or just greater if not.
int pred(ll m, ll h, ll a[], ll n)
{
    if (!can_rm(m, h, a, n))
        return 0;

    else
        return 1;
}
int main()
{
    // ye 2 line pta nhi kya hai
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, h;
    cin >> n >> h;
    ll a[n];
    ll r = -1;
    rep(i, n)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    r++;
    ll l = 0;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (pred(m, h, a, n) == 0)
            l = m;
        else
            r = m;
    }
    cout << r;

    return 0;
}
