#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{

    int _;
    cin >> _;

    while (_--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int mask = 1;
        int x=0;
        int fg=0;
        for (int i = 1; i < 31; i++)
        {
            if (((mask & c) == 0) && ((mask & a) != 0) && ((mask & b) != 0))
            {
                cout << -1 br;
                fg = 1;
                break;
            }
            if ((((a & mask) == 0) || ((b & mask) == 0)) && ((c & mask) != 0)){
                x|=mask;
            }
            mask<<=1;
        }
        if (fg != 1)
        {
            cout << x br;
        }
    }
    return 0;
}
