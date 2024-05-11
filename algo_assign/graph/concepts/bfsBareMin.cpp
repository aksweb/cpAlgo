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

// comparator
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

void findPath(string src, string dest, vector<string> &path, unordered_map<string, string> &parent, vector<pair<string, pair<string, string>>> &graph)
{
    if (src == dest)
    {
        int fg = 0;
        for (auto pair : parent)
        {
            if (pair.first == src && pair.second == dest)
            {
                for (auto x : graph)
                {
                    if (x.first == src && x.second.first == dest)
                    {
                        path.pb(x.second.second);
                        fg = 1;
                        break;
                    }
                }
            }
            if (fg == 1)
                break;
        }
        return;
    }
    findPath(src, parent[dest], path, parent, graph);
    int fg = 0;
    for (auto edge : graph)
    {
        if (edge.first == parent[dest] && edge.second.first == dest)
        {
            path.pb(edge.second.second);
            break;
        }
    }
}

// Code Begins Here
void bfs(vector<vector<int>> adjList, int src, vector<bool> vis, vector<int> &ans)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    ans.pb(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto near : adjList[node])
        {
            if (!vis[near])
            {
                ans.pb(near);
                q.push(near);
                vis[near] = true;
            }
        }
    }
}

void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> adjList(5);
    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    vector<bool> vis(5, false);
    vector<int> ans;
    bfs(adjList, 0, vis, ans);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}