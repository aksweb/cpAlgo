#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repn(i, m, n) for (ll i = m; i >= n; i--)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> a[i][j];
        }
    }
    ll r = 0, c = 0;
    while (r < n && c < m)
    {
        // Print the first row from the remaining rows
        rep(i, c, m) cout << a[r][i] << " ";
        r++;

        // Print the last column from the remaining columns
        rep(i, r, n) cout << a[i][m - 1] << " ";
        m--;

        // Print the last row from the remaining rows
        if (r < n)
        {
            repn(i, m - 1, c) cout << a[n - 1][i] << " ";
            n--;
        }

        // Print the first column from the remaining columns
        if (c < m)
        {
            repn(i, n - 1, r) cout << a[i][c] << " ";
            c++;
        }
    }

    return 0;
}
