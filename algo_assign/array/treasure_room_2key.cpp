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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    ll a[n];
    unordered_map<int, int> mp;
    rep(i, n)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    bool fg = 0;
    while (l < r)
    {
        if (a[l] + a[r] == m)
        {
            cout << mp[a[l]] + 1 << " " << mp[a[r]] + 1 br;
            fg = 1;
            break;
        }
        else if (a[l] + a[r] > m)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    if (!fg)
        cout << -1;

    return 0;
}
