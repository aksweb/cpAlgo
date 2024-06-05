#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll INF = 1e9;
enum
{
    T,
    B,
    L,
    R
};
void add_edge(vector<vector<long long>> &adj, long long u, long long v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
long long d2(long long x1, long long y1, long long x2, long long y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
vector<bool> bfs(long long source, vector<vector<long long>> &adj)
{
    long long n = adj.size();
    vector<bool> vis(n);
    queue<long long> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty())
    {
        long long v = q.front();
        q.pop();
        for (long long u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = true;
                q.push(u);
            }
        }
    }
    return vis;
}

void solve()
{
    long long x, y, n;
    cin >> x >> y >> n;
    vector<array<long long, 3>> circles(n);
    rep(i, 0, n)
    {
        for (long long j = 0; j < 3; ++j)
        {
            cin >> circles[i][j];
        }
    }
    vector<vector<long long>> adj(n + 4);
    // edges with boundary
    rep(i, 0, n)
    {
        long long idx = i + 4;
        if (circles[i][0] - circles[i][2] <= 0)
            add_edge(adj, L, idx);
        if (circles[i][0] + circles[i][2] >= x)
            add_edge(adj, R, idx);
        if (circles[i][1] - circles[i][2] <= 0)
            add_edge(adj, B, idx);
        if (circles[i][1] + circles[i][2] >= y)
            add_edge(adj, T, idx);
    }
    // chains
    rep(i, 0, n)
    {
        long long idxi = i + 4;
        for (long long j = i + 1; j < n; ++j)
        {
            long long idxj = j + 4;
            if (d2(circles[i][0], circles[i][1], circles[j][0],
                   circles[j][1]) <= (circles[i][2] +

                                      circles[j][2]) *

                                         (circles[i][2]

                                          + circles[j][2]))

                add_edge(adj, idxi, idxj);
        }
    }
    vector<bool> TV = bfs(T, adj);

    vector<bool> BV = bfs(B, adj);
    vector<bool> LV = bfs(L, adj);
    vector<bool> RV = bfs(R, adj);
    bool ans = not(TV[B] or TV[L] or BV[T] or BV[R] or LV[T] or LV[R] or

                   RV[B] or RV[L]);
    cout << (ans ? "YES" : "NO") << endl;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}