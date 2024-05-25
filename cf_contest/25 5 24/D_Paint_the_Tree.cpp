#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bfs(int start, const vector<vector<int>> &adj, int n)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a, b;
        cin >> a >> b;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> distA = bfs(a, adj, n);
        vector<int> distB = bfs(b, adj, n);

        int maxDistA = *max_element(distA.begin() + 1, distA.end());
        int maxDistB = *max_element(distB.begin() + 1, distB.end());

        int result = maxDistB + (maxDistA - maxDistB) * 2;
        cout << result << '\n';
    }

    return 0;
}
