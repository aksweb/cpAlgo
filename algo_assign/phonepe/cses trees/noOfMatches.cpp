// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(ll u, vector<vector<ll>> &adj, vector<bool> &vis, ll &matching_edges)
{
    vis[u] = true;
    for (ll v : adj[u])
    {
        if (!vis[v])
        {
            vis[v] = true;    // Mark the neighbor as visited
            matching_edges++; // Count this as a matching edge
            return;           // Stop further exploration for this node
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<bool> vis(n, false);
    ll matching_edges = 0;

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, matching_edges);
    }

    cout << matching_edges << "\n";

    return 0;
}
