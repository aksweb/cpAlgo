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
        ll a, b, c;
        cin >> a >> b >> c;
        ll red = c + b - a;
        ll green = a + b - c;
        ll blue = a + c - b;
        if (red >= 0 && blue >= 0 && green >= 0)
            cout << "YES" br;
        else
            cout << "NO" br;
    }

    return 0;
}
