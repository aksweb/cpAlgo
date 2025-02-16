#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll _;
    cin >> _;
    while (_--)
    {
        ll n, m, q, d;
        cin >> n >> m >> q;
        vector<ll> pos(m);
        for (ll i = 0; i < m; i++)
            cin >> pos[i];
        cin >> d;
        ll lfg = -1, rfg = n;
        for (ll i = 0; i < m; i++)
        {
            if (pos[i] < d)
            {
                lfg = max(lfg, pos[i]);
            }
            else if (pos[i] > d)
            {
                rfg = min(rfg, pos[i]);
            }
        }
        if(lfg==1 ||rfg==n){
            cout<<max()
        }
        cout << lfg << " " << d << " " << rfg << endl;
        if (rfg - d > d - lfg)
        {
            cout << (rfg - (d - lfg)) / 2 + (d - lfg) << endl;
        }
        else
        {
            cout << 0 << endl;
            // cout << (d - (lfg + (rfg - d))) / 2 + (rfg - d) << endl;
        }
    }
    return 0;
}
