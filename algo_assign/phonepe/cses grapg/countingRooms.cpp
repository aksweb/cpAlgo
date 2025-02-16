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

int main()
{
    int n, m;
    cin >> n >> m;
    char a[n][m];
    rep(i, n)
    {
        rep(j, m) cin >> a[i][j];
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            if (!vis[i][j] && a[i][j] == '.')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                ans++;
                // cout << i << " " << j br;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    rep(k, 4)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == '.')
                        {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
