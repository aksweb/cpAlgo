// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll MOD = 1e9 + 7;

// Global Variables
vector<vector<int>> adj;
unordered_set<int> cameras;

void dfs(int node, int parent)
{
    for (int v : adj[node])
    {
        if (v != parent)
        {
            dfs(v, node);

            if (cameras.find(v) == cameras.end() && cameras.find(parent) == cameras.end())
            {
                // cout << "v: " << v << " ";
                cameras.insert(node);
                // cout<<"camera req at: "<<
            }
            else if (adj[v].size() == 1 && cameras.find(node) == cameras.end())
            {
                // cout << "v: " << v << " ";
                cameras.insert(v);
            }
        }
    }
}
void bfs(int root, int parent)
{
    queue<pair<int, int>> q;
    q.push({root, parent});
    vector<bool> visited(adj.size(), false);

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        visited[node] = true;

        // Check if both leaf nodes of the last node have cameras installed

        int count = 0;
        if (adj[node].size() == 3)
        {
            for (auto i : adj[node])
            {
                if (i != parent)
                {

                    if (cameras.find(i) != cameras.end())
                        count++;
                }
            }
        }
        if (count == 2)
        {
            cameras.insert(node);
            for (auto i : adj[node])
            {
                if (i != parent)
                    cameras.erase(i);
            }
        }
        for (int child : adj[node])
        {
            if (!visited[child])
            {
                q.push({child, node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    bfs(1, 0);
    // for (auto x : cameras)
    //     cout << x << " ";
    cout << cameras.size();

    // combining leaf node to one if possible through bfs
    //    write bfs code here

    return 0;
}
