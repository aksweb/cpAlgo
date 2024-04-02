// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
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

int pred(ll a[], ll m, ll n, ll nop)
{
    ll cop = 0;
    rep(i, n)
    {
        cop += ceil((a[i] * 1.0) / m);
    }
    // cout << "cop: "<< " " << cop br;
    if (cop <= nop)
        return 1;
    else
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
        ll n, nop;
        cin >> n >> nop;
        ll a[n];
        ll mx = -1;
        ll zc = 0;
        rep(i, n)
        {
            cin >> a[i];
            if (a[i] == 0)
                zc++;
            mx = max(mx, a[i]);
        }
        if (zc == n)
        {
            cout << 0 br;
            continue;
        }
        ll l = 0, r = mx + 1;
        while (l + 1 < r)
        {
            ll m = l + (r - l) / 2;

            if (pred(a, m, n, nop) == 0)
                l = m;
            else
                r = m;
        }
        if (r == mx + 1 && (l == mx))
            cout << -1 br;
        else
            cout << r br;
        // }
    }
    return 0;
}
