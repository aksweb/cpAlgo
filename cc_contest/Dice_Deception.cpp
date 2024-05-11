#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        ll s = 0;
        rep(i, n)
        {
            cin >> a[i];
            s += a[i];
        }
        sort(a, a + n);
        ll ans = s;
        int mp[7] = {0, 6, 5, 4, 3, 2, 1};
        for (ll i = 0; i < k; i++)
        {
            s -= a[i];
            s += mp[a[i]];
            // cout << mp[a[i]] << " ";
            ans = max(ans, s);
        }
        cout << ans br;
    }

    return 0;
}