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
// isse achha approach nhi melega bhai.

// Code 
vector<int> dp, vis;
vector<vector<int>> adj;

void dfs(int u)
{
    vis[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
            dp[u] += dp[v];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    vis.resize(n + 1);
    dp.resize(n + 1, 1);

    for (int i = 2; i <= n; ++i)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
    {
        cout << dp[i] - 1 << " ";
    }
    return 0;
}
