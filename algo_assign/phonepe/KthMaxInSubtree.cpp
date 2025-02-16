#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function for the Euler Tour
void computeByDfs(const vector<vector<ll>> &adj, vector<ll> &euler, vector<ll> &start, vector<ll> &end, ll root, ll parent)
{
    start[root] = euler.size();
    euler.push_back(root);
    for (ll child : adj[root])
    {
        if (child != parent)
        {
            computeByDfs(adj, euler, start, end, child, root);
        }
    }
    end[root] = euler.size() - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vector<ll> val(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 1: Perform Euler Tour
    vector<ll> euler, start(n), end(n);
    computeByDfs(adj, euler, start, end, 0, -1);

    // Step 2: Create Subtree Sorted Values
    vector<vector<ll>> sortedTree(n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = start[i]; j <= end[i]; j++)
        {
            sortedTree[i].push_back(val[euler[j]]);
        }
        sort(sortedTree[i].rbegin(), sortedTree[i].rend()); 
    }

    // Step 3: Queries
    while (q--)
    {
        ll node, k;
        cin >> node >> k;
        node--;
        if (k <= sortedTree[node].size())
        {
            cout << sortedTree[node][k - 1] << "\n"; //  k-th largest
        }
        else
        {
            cout << -1 << "\n"; 
        }
    }

    return 0;
}
