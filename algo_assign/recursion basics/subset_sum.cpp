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

void minDiff(vector<ll> &v, ll n, ll ind, ll &diff, ll s1, ll s2)
{
    if (ind == n)
    {
        diff = min(diff, abs(s1 - s2));
        return;
    }
    minDiff(v, n, ind + 1, diff, s1 + v[ind], s2);
    minDiff(v, n, ind + 1, diff, s1, s2 + v[ind]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll diff = LLONG_MAX;
    ll s1 = 0, s2 = 0;
    ll ind = 0;
    minDiff(v, n, ind, diff, s1, s2);
    cout << diff;

    return 0;
}
