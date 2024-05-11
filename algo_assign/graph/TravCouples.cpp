// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// isse achha approach nhi melega.
// question r k l
// cnts
// tcs

// Code Begins Here
void bfs(int src, vector<vector<int>> adjList, vector<bool> vis, vector<int> &dist)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto near : adjList[node])
        {
            if (!vis[near])
            {
                dist[near] = dist[node] + 1;
                q.push(near);
                vis[near] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c1, c2, c3, n, p;
    cin >> c1 >> c2 >> c3 >> n >> p;
    vector<vector<int>> graph(n + 1);

    rep(i, p)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> dist1(n + 1, 0);
    vector<int> dist2(n + 1, 0);
    vector<int> dist3(n + 1, 0);

    vector<bool> vis(n + 1, false);
    bfs(1, graph, vis, dist1);
    bfs(2, graph, vis, dist2);
    bfs(n, graph, vis, dist3);

    ll mini = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        ll temp = dist1[i] * c1 + dist2[i] * c2 + dist3[i] * c3;
        mini = min(mini, temp);
    }
    cout << mini;
    return 0;
}