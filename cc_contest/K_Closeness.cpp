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
        vector<ll> pans;
        rep(i, n)
        {
            cin >> a[i];
            pans.pb(a[i] % k);
        }

        sort(pans.begin(), pans.end());
        ll ans = pans[n - 1] - pans[0];
        rep(i, n - 1)
        {
            ans = min(ans, pans[i] + k - pans[i + 1]);
        }
        cout << ans br;
    }

    return 0;
}