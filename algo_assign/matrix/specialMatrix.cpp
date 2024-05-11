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

// print the 1st index
int pred(ll m, ll b)
{
    if (m < b)
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll a[n][n];

    rep(i, n)
    {
        rep(j, n) cin >> a[i][j];
    }

    vector<ll> rsum, csum;
    ll cmax = 0, rmax = 0;
    rep(i, n)
    {
        ll temp = 0;
        rep(j, n)
        {
            temp += a[i][j];
        }
        rmax = max(temp, rmax);
        rsum.push_back(temp);
    }
    rep(i, n)
    {
        ll temp = 0;
        rep(j, n)
        {
            temp += a[j][i];
        }
        csum.push_back(temp);
        cmax = max(cmax, temp);
    }
    ll same = max(rmax, cmax);
    ll ans = 0;
    rep(i, n)
    {
        ll t1 = rsum[i];
        rep(j, n)
        {
            ll t2 = csum[j];
            if (a[i][j] != same)
            {
                ll change = min(same - t1, same - t2);
                a[i][j] += change;
                ans += change;
                rsum[i] += change;
                csum[j] += change;
            }
        }
    }
    cout << ans br;

    return 0;
}
