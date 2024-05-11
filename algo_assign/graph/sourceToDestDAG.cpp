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
bool bfs(string src, string dest, vector<string> &path, vector<pair<string, pair<string, string>>> graph)
{
    queue<string> q;
    unordered_map<string, bool> vis;

    unordered_map<string, string> parent;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        string str = q.front();
        q.pop();
        for (auto edge : graph)
        {
            if (edge.first == str && !vis[edge.second.first])
            {
                parent[edge.second.first] = edge.first;
                q.push(edge.second.first);
                vis[edge.second.first] = true;
                if (edge.second.first == dest)
                {
                    findPath(src, edge.second.first, path, parent, graph);
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<string, pair<string, string>>> graph;

    rep(i, m)
    {
        string c1, c2, rd;
        cin >> c1 >> c2 >> rd;
        graph.pb({c1, {c2, rd}});
    }
    // for (auto x : graph)
    // {
    //     cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    // }
    string src, dest;
    cin >> src >> dest;

    vector<string> path;

    if (bfs(src, dest, path, graph))
    {
        cout << path.size() br;
        for (auto p : path)
            cout << p br;
    }
    else
        cout << "Impossible";

    return 0;
}