// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Code Begins Here

int main()
{

    ll test;
    cin >> test;
    while (test--)
    {
        ll a, b;
        cin >> a >> b;
        ll diff = abs(a - b);
        ll mn = min(a, b);
        ll mx = max(a, b);
        if (a >= (2 * b) || b >= (2 * a))
            cout << 0 << endl;
        else
        {

            ll ans1 = abs(mx / 2 - mn);
            ll ans2 = abs(2 * mn - mx);
            cout << min(ans1, ans2) << endl;
        }
    }

    return 0;
}
