#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define nCr(n, r) (tgamma(n + 1) / (tgamma(r + 1) * tgamma(n - r + 1)))

int main()
{

    ll test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        vector<int> a(n);
        unordered_map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        if (mp.size() == 1)
        {
            cout << nCr(mp[a[0]], 2) << endl;
        }
        else
        {
            ll mxCount = 0, mx;
            for (auto x : mp)
            {
                if (x.first != 0 && x.second > mxCount)
                {
                    mx = x.first;
                    mxCount = x.second;
                }
            }
            ll ans = 0;
            if (mp[0] > 0)
            {
                ans += nCr(mp[0] + mp[mx], 2);
                mp.erase(mx);
            }
            for (auto x : mp)
            {
                if (x.first != 0)
                {
                    ans += nCr(x.second, 2);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
