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
        ll a, b, x;
        cin >> a >> b >> x;
        if (a * b <= x * x)
            cout << 0 br;
        else
        {
            ll sq_area = x * x;
            if ((sq_area / min(a, b)) >= 1)
                cout << 1 br;
            else
                cout << 2 br;
        }
    }

    return 0;
}