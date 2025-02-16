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
int bfs(vector<vector<int>> graph, int src, int dest)
{
    queue<int> q;
    vector<bool> vis(graph.size(), false);
    q.push(src);
    int jumps = 0;

    vector<int> distance(graph.size(), 0);
    while (!q.empty())
    {
        int u = q.front();
        if (u == dest)
            return distance[u];
        q.pop();
        jumps++;
        for (auto x : graph[u])
        {
            if (vis[x] == false)
            {
                distance[x] = distance[u] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "12345";
    cout << s.substr(1, 3);

    return 0;
}