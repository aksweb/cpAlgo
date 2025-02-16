// ABHISHEKH786 RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// rec+memo will not work since i/p is 1e9 type, not possible to store in memory

void solve()
{
    ll a, b;
    cin >> a >> b;
    if ((a == 0 && b != 0) || (b == 0 && a > 0))
    {
        cout << "NO\n";
        return;
    }
    // by formula x +2y =a, 2*x +y =b
    ll y1 = ((2 * a) - b) / 3;
    ll x1 = ((2 * b) - a) / 3;

    // by formula 2x +y =a, x +2y =b
    ll y2 = ((2 * b) - a) / 3;
    ll x2 = ((2 * a) - b) / 3;

    // also all values >=0  since picking up cant be -ve
    if (((x1 + (2 * y1) == a) && ((2 * x1) + y1 == b) && (x1 >= 0 && y1 >= 0)) || (((2 * x2) + y2 == a) && ((2 * y2) + x2 == b) && (x2 >= 0 && y2 >= 0)))
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ll _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}