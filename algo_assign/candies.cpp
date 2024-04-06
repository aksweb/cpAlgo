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

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i, n) cin >> a[i];
    if (n < m)
    {
        cout << -1;
        return 0;
    }
    int rq = n - m + 1;

    ll l = 0, r = n;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (pred(a[m], s) == 0)
        {
            l = m;
            if (l != i && l != j)
                ans++;
        }
        else
            r = m;
    }

    return 0;
}
