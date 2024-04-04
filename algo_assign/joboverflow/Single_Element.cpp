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
        return a.first >
               b.first;
}

int pred(ll a[], ll m, ll n)
{
    // same at end
    if (m == n - 1)
    {
        if (a[m] == a[m - 1])
            return 1;
        else
            return 0;
    }
    if ((m % 2) == 0)
    {
        if ((m + 1) < n && (a[m] != a[m + 1]))
            return 1;
        else
            return 0;
    }
    else
    {
        if ((m - 1) >= 0 && (a[m] != a[m - 1]))
            return 1;
        else
            return 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];

        if (n == 1)
        {
            cout << a[0] br;
            continue;
        }
        ll l = 0, r = n - 1;
        while (l + 1 < r)
        {
            ll m = l + (r - l) / 2;
            if (pred(a, m, n) == 0)
                l = m;
            else
                r = m;
        }
        if ((r < n - 1) && a[r] == a[r + 1])
            cout << a[l] br;
        else
            cout << a[r] br;
    }
    return 0;
}
