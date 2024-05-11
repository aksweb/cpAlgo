
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];
        ll v = a[0];
        int fg = 0;
        if (a[0] != a[n - 1])
        {
            cout << "NO" br;
            continue;
        }
        for (ll i = 1; i < n - 1; i++)
        {
            if (a[i] < v)
            {
                fg = 1;
                break;
            }
        }
        if (fg == 1)
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
