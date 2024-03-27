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

// printing last occurence if found or just greater if not.
int pred(ll m, ll w, ll h, ll t)
{
    ll t1 = m / w;
    ll t2 = m / h;
    if (t1 <= 0 || t2 <= 0)
    {
        return 0;
    }
    else if (t1 > 0 && t2 > 0)
    {
        // ll height = m / h;
        // ll width = m / w;
        // if (height > 1e18 / width)
        //     return true;
        // return height * width >= t;

        if (static_cast<long double>(t2) < static_cast<long double>(t) / t1 || static_cast<long double>(t1) < static_cast<long double>(t) / t2)
            return 0;

        else
            return 1;
    }
    else
        return 1;
}

int main()
{
    // ye 2 line pta nhi kya hai
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll w, h, t;
        cin >> w >> h >> t;

        ll n = (w + h) * t;
        ll l = 0, r = n;

        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (pred(m, w, h, t) == 0)
                l = m;
            else
                r = m;
        }
        cout << r br;
    }

    return 0;
}
