// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _;
    cin >> _;
    while (_--)
    {
        ll s, n;
        cin >> s >> n;

        vector<string> strings(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> strings[i];
        }

        ll ans = 0;
        for (ll j = 0; j < s; j++)
        {
            ll zc = 0, oc = 0, qc = 0;

            for (ll i = 0; i < n; i++)
            {
                if (strings[i][j] == '0')
                {
                    zc++;
                }
                else if (strings[i][j] == '1')
                {
                    oc++;
                }
                else
                {
                    qc++;
                }
            }

            ll ht = n / 2;

            ll mxz, mxo;

            if (zc <= oc)
            {
                mxz = min(zc + qc, ht);
                mxo = n - mxz;
            }
            else
            {
                mxo = min(oc + qc, ht);
                mxz = n - mxo;
            }

            ans += mxz * mxo;
        }

        cout << ans << endl;
    }

    return 0;
}
