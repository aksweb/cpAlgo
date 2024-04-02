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

int pred(ll m, ll x)
{
    if (m < x)
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
    ll a[n];
    rep(i, n) cin >> a[i];
    ll k, x;
    cin >> k >> x;

    priority_queue<pair<ll, ll>> pq;
    rep(i, n)
    {
        if (a[i] != x)
            pq.push({-abs(a[i] - x), -a[i]});
    }
    int count = k;
    vector<ll> ans;
    while (count > 0)
    {
        if (pq.size() == 0)
            break;
        ans.push_back(-pq.top().second);
        pq.pop();
        count--;
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) cout << ans[i] << " ";
    return 0;
}