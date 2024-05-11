// ABHISHEKH786
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

// q r k l
// const
// tc
// isse a approach n m b.

// Code
vector<int> vis, teamP;
vector<vector<int>> adj;
int maxP = INT_MIN;
void dfs(int u)
{
    vis[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
            teamP[u] += teamP[v];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    vis.resize(n + 1);
    teamP.resize(n + 1, 0);

    for (int i = 2; i <= n; ++i)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> teamP[i];
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
    {
        // cout << teamP[i] << " ";
        maxP = max(maxP, teamP[i]);
    }
    cout << maxP;
    return 0;
}
