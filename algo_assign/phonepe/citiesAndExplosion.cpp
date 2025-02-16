#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br '\n'
#define rep(i, n) for (ll i = 0; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

void dfs(vector<vector<ll>> &adj, vector<bool> &vis, ll node, ll no)
{
    vis[node] = true;
    for (ll x : adj[node])
    {
        if (!vis[x] && x > no)
            dfs(adj, vis, x, no);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n); // Initialize adjacency list
    rep(i, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1); 
        adj[v - 1].push_back(u - 1); 
    }

    vector<ll> res(n, 0);

    for (ll i = n - 1; i >= 0; i--)
    {
        vector<bool> vis(n, false);
        ll components = 0;

        vis[i] = true; // Mark the current city as destroyed
        for (ll j = i + 1; j < n; j++)
        { // Start DFS from remaining nodes
            if (!vis[j])
            {
                dfs(adj, vis, j, i);
                components++; // Increment for every new connected component
            }
        }

        res[i] = components;
    }

    rep(i, n) cout << res[i] << br;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
