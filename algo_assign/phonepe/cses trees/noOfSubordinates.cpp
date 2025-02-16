// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// Code Begins Here
void eulerDfs(ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &euler, vector<ll> &start, vector<ll> &end)
{
    start[node] = euler.size();
    euler.push_back(node);

    for (ll x : adj[node])
    {
        if (x != parent)
        {
            eulerDfs(x, node, adj, euler, start, end);
        }
    }
    end[node] = euler.size() - 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for (ll i = 1; i < n; i++)
    {
        ll e;
        cin >> e;
        adj[i].push_back(e - 1);
        adj[e - 1].push_back(i);
    }

    // make euler path for entry only
    vector<ll> euler;
    vector<ll> start(n);
    vector<ll> end(n);
    eulerDfs(0, -1, adj, euler, start, end);

    // vector<ll>ans(n);
    for (ll i = 0; i < n; i++)
    {
        cout << end[i] - start[i] << " ";
    }
    return 0;
}
