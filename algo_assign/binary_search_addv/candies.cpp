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
// constraints
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

// printing last occurence since we are not sure whether i will able to get equality  or not, if not we want the smaller one.
int pred(ll m, ll n)
{

    if (static_cast<long double>(m) <= static_cast<long double>(n) / static_cast<long double>(m))
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    ll nn = n;
    // taking i*i+1 = i^2 assumption
    n = 2 * n;

    ll l = -1, r = n;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (pred(m, n) == 0)
            l = m;
        else
            r = m;
    }

    if (static_cast<long double>(l + 1) <= 2 * static_cast<long double>(nn) / static_cast<long double>(l))
    {
        cout << l;
    }
    else
        cout << l - 1;

    return 0;
}