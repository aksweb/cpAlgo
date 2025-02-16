#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool pred(ll m, vector<ll> &barn, ll c)
{
    ll st = 0;
    c--;
    for (ll i = 1; i < barn.size(); i++)
    {
        if (barn[i] - barn[st] >= m)
        {
            st = i;
            c--;
            if (c == 0)
                return true;
        }
    }
    return false;
}
int main()
{
    ll _;
    cin >> _;
    while (_--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> barn(n);
        for (ll i = 0; i < n; i++)
            cin >> barn[i];
        sort(barn.begin(), barn.end());
        ll h = barn[n - 1] - barn[0];
        ll l = 1;

        ll ans = 0;
        while (l <= h)
        {
            ll m = l + (h - l) / 2;
            if (pred(m, barn, c))
            {
                ans = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }
        cout << ans << endl;
    }

    return 0;
}