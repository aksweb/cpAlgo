#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br '\n'
#define rep(i, n) for (ll i = 0; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

ll bs(ll k, vector<ll> &prefix, ll idx)
{
    ll l = 0, h = idx;
    ll ans = 0;
    while (l <= h)
    {
        ll m = l + (h - l) / 2;
        if (prefix[idx] - (m > 0 ? prefix[m - 1] : 0) <= k) // Handle prefix[0]
        {
            ans = max(ans, idx - m + 1);
            h = m - 1; // Narrow down to smaller subarrays
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> prefix(n, 0);
    prefix[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, bs(k, prefix, i));
    }
    cout << ans << br;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
