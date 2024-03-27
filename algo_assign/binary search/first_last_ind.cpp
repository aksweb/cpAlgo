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

int predf(ll m, ll b)
{
    if (m >= b)
        return 1;
    else
        return 0;
}
int predl(ll m, ll b)
{
    if (m <= b)
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    ll a[n];
    rep(i, n) cin >> a[i];

    rep(i, q)
    {
        int st = 0, end = 0;
        ll b;
        cin >> b;

        // finding first index
        int l = -1, r = n;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (predf(a[m], b) == 0)
                l = m;
            else
                r = m;
        }
        st = r;

        // finding last index
        l = -1, r = n;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (predl(a[m], b) == 0)
                l = m;
            else
                r = m;
        }
        end = l;
        if (end - st < 0)
            cout << -1 << " " << -1 br;
        else
            cout << st << " " << end br;
    }

    return 0;
}
