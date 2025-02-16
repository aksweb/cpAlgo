#include <bits/stdc++.h>
using namespace std;
int n, m, c1, c2, c3;
vector<vector<int>> g;
vector<int> bfs(int src)
{
    vector<int> dist(n + 1, -1);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int main()
{
    cin >> c1 >> c2 >> c3 >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d1 = bfs(1);
    vector<int> d2 = bfs(2);
    vector<int> d3 = bfs(n);
    int ans = (long long)d1[n] * c1 +
              (long long)d2[n] * c2;

    for (int i = 1; i <= n; i++)
    {
        int tans = (long long)d1[i] * c1 +
                   (long long)d2[i] * c2 +
                   (long long)d3[i] * c3;

        ans = min(ans, tans);
    }
    cout << ans << endl;
    return 0;
}
e