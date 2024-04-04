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
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll mxa = -1, mxb = -1;
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n)
    {
        cin >> a[i];
        mxa = max(mxa, a[i]);
    }

    ll m;
    cin >> m;
    ll b[m];
    rep(i, m)
    {
        cin >> b[i];
        mxb = max(b[i], mxb);
    }

    vector<bool> va(mxa + 1, false);
    vector<bool> vb(mxb + 1, false);

    // marking vis-a and vis-b
    rep(i, m)
    {
        if (b[i] <= mxa)
            va[b[i]] = true;
    }

    rep(i, n)
    {
        if (a[i] <= mxb)
            vb[a[i]] = true;
    }
    vector<ll> ans;
    rep(i, n)
    {
        if (!va[a[i]])
            ans.push_back(a[i]);
    }
    rep(i, m)
    {
        if (!vb[b[i]])
            ans.push_back(b[i]);
    }
    // rep(i, ans.size()) cout << ans[i] << " ";
    cout << ans.size();
    return 0;
}
