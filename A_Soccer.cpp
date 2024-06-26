// TESTEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _;
    cin >> _;
    while (_--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a > b && d > c) || (b > a && c > d))
        {
            cout << "NO" br;
        }
        else
        {
            cout << "YES" br;
        }
    }
    return 0;
}
