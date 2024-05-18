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
        int a[3];

        cin >> a[0] >> a[1] >> a[2];
        if ((a[0] + a[1] + a[2]) % 2 != 0)
        {
            cout << -1 br;
            continue;
        }
        sort(a, a + 3);
        int ans = 0;
        rep(i, 0, 3)
        {
            if (a[i] % 2 == 0 && (a[i] / 2) > 0)
            {
                ans += (a[i] / 2) + 1;
            }
            else if (a[i] > 0)
            {
                ans += a[i] / 2;
            }
        }

        cout << ans br;
    }
    return 0;
}
