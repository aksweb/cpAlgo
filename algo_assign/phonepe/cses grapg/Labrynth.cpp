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

void solve(int si, int sj, int ei, int ej, int n, int m, char &a[n][m])
{
    if(a[i][j]=='#')return INT_MAX;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++)
    {
        int nx=i+dx[k];
        int ny= j+dy[k];
        if(nx>=0 && ny>=0 && nx<n && ny<m){
            if(a[nx][ny]=='.'){
                return solve
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    char a[n][m];
    pair<int, int> start, end;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
            if (a[i][j] == 'B')
            {
                end.first = i;
                end.second = j;
            }
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;

    int ans = solve()
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
