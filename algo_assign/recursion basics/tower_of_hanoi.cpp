// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
// #define pb push_back
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

void toh(vector<pair<int, pair<int, int>>> &ans, ll n, int a, int b, int c, ll &count)
{
    if (n == 0)
        return;

    toh(ans, n - 1, a, c, b, count);

    ans.push_back({n, {a, b}});
    count++;

    toh(ans, n - 1, c, b, a, count);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<pair<int, pair<int, int>>> ans;

    ll count = 0;
    int from = 1, to = 2, via = 3;
    toh(ans, n, from, to, via, count);
    cout << count br;

    for (auto x : ans)
        cout << x.first << " " << x.second.first << " " << x.second.second br;

    return 0;
}
