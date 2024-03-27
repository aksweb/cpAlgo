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

int pred(ll m, ll b)
{
    if (m >= b)
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    ll a[n];
    rep(i, n)
    {
        cin >> a[i];
    }
    ll ans = 0;
    rep(i, n)
    {

        ll temp = a[i] + d;

        ll l = -1, r = n;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (pred(temp, a[m]) ==0 )
                l = m;
            else
                r = m;
        }
        if (r != n)
        {
            ans += ((r - i) * (r - i - 1)) / 2;
        }
    }
    cout << ans br;

    return 0;
}
