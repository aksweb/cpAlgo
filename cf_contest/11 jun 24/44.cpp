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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> grid[i];
        }

        int mnx = n, mxx = -1, mny = m, mxy = -1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '#')
                {
                    mnx = min(mnx, i);
                    mxx = max(mxx, i);
                    mny = min(mny, j);
                    mxy = max(mxy, j);
                }
            }
        }

        cout << (mnx + mxx) / 2 + 1 << " " << (mny + mxy) / 2 + 1 br;
    }

    return 0;
}
