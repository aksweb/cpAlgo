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

    int _;
    cin >> _;

    while (_--)
    {
        int x, y;
        cin >> x >> y;

        int den = 100 - y;
        int num = 10 * (y - x);

        int additional_hours = (num + den - 1) / den;

        cout << additional_hours << endl;
    }

    return 0;
}
