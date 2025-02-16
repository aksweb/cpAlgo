
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        if (n == 0)
            cout << 0 << endl;
        else
            cout << (ll)ceil((n * 1.0) / (min(x, y))) << endl;
    }

    return 0;
}
