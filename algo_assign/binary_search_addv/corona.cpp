// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
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

// predicate
int pred(ll m, vector<pair<ll, ll>> &island, ll n)
{

    ll nop = 0;
    ll prev = -1e18;
    for (auto it : island)
    {
        ll st = max(it.first, prev + m);

        while (st <= it.second)
        {
            nop++;
            prev = st;
            st += m;
            if (nop >= n)
                return 1;
        }
    }
    return 0;
}

int main()
{
    // ye 2 line pta nhi kya hai
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> island(m);
    rep(i, m)
    {
        cin >> island[i].first >> island[i].second;
    }
    sort(island.begin(), island.end());

    ll l = -1, r = 1e18;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        if (pred(mid, island, n) == 1)
            l = mid;
        else
            r = mid;
    }
    cout << l;

    return 0;
}
