// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
// #define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;
vector<vector<int>> adj;
// vector<bool> vis;

bool dfs(int src, vector<int> &color)
{
    color[src] = 1;

    for (auto v : adj[src])
    {
        if (color[v] == 1)
            return true;
        if (color[v] == 0)
        {
            if (dfs(v, color))
                return true;
        }
    }
    // will not take any path from this node
    color[src] = 2;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n);
    // vis.resize(n, false);
    // vector<bool> recStack(n, false);
    vector<int> color(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool val = false;
    rep(i, n)
    {
        if (color[i] == 0)
        {
            val = dfs(i, color);
        }
        if (val)
        {
            cout << "NO" br;
            return 0;
        }
    }
    cout << "YES" br;

    return 0;
}
