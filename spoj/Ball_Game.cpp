#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        ll p[n], v[n];
        for (ll i = 0; i < n; i++)
            cin >> p[i];
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        vector<pair<ll, ll>> vp(n);
        for (int i = 0; i < n; i++)
        {
            vp[i] = {p[i], v[i]};
        }

        sort(vp.begin(), vp.end());

        vector<long double> t(n);
        for (ll i = 0; i < n; i++)
            t[i] = ((long double)vp[i].first / (long double)vp[i].second);

        long double last = t[n - 1];
        ll total = n;
        for (ll i = n - 2; i >= 0; i--)
        {
            if (t[i] > last)
            {
                total--;
            }
            else
            {
                last = t[i];
            }
        }

        cout << total << endl;
    }
    return 0;
}
