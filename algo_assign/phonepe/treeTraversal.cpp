// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    rep(i, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    // traversing the tree
    //  let me give you the starting node of the tree and you have to print the whole tree
    //  you can use DFS or BFS to do this
    // BFS approach
    ll start;
    cin >> start;
    // cout << "Give starting node\n";

    queue<ll> q;
    q.push(start - 1);
    vector<bool> vis(n, false); // Keep track of visited nodes
    vis[start - 1] = true;
    ll cnt = 0;
    while (!q.empty())     {
        ll node = q.front();
        q.pop();
        cout << node + 1 << ", ";
        for (ll x : adj[node])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        }
    }

    return 0;
}