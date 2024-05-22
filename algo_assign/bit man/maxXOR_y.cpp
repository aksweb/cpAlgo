#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        ll x, l, r;
        cin >> x >> l >> r;
        ll y = 0;
        for (ll i = 30; i >= 0; i--)
        {
            ll val = (1 << i);
            if (x & val)
            {
                if ((y + val - 1) < l)
                {
                    y += val;
                }
            }
            else
            {
                if (y + val <= r)
                {
                    y += val;
                }
            }
        }
        cout << (x ^ y) br;
    }
    return 0;
}