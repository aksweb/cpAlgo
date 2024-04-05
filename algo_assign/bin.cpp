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

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int pred(int m)
{
    if (m == 1)
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int l = -1, r = n;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (pred(a[m]) == 0)
            l = m;
        else
            r = m;
    }

    return 0;
}
