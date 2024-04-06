// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        cout << ceil(log(n) / log(2)) br;
    }
    return 0;
}
