// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// isse achha approach nhi melega.
// question r k l
// cnts
// tcs

// Code Begins Here
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

int dfs(vector<vector<int>> &arr, vector<vector<int>> &vis, int i, int j)
{
    vis[i][j] = 1;
    int res = 1;
    rep(k, 0, 4)
    {
        int dx = i + dr[k];
        int dy = j + dc[k];
        if (dx < 0 || dy < 0 || dx >= arr.size() || dy >= arr[0].size() || vis[dx][dy] == 1 || arr[dx][dy] == 0)
            continue;
        res += dfs(arr, vis, dx, dy);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (vis[i][j] == 0 && arr[i][j] == 1)
            {
                ans = max(ans, dfs(arr, vis, i, j));
                vis[n - 1][m - 1] = 0;
            }
        }
    }
    cout << ans br;

    return 0;
}