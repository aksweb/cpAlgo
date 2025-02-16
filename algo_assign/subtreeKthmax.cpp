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
void computeByDfs(vector<vector<ll>> &adj, vector<ll> &euler, vector<ll> &start, vector<ll> &end, ll root, ll parent)
{
    start[root] = euler.size();
    euler.push_back(root);
    for (ll x : adj[root])
    {
        if (x != parent)
        {
            computeByDfs(adj, euler, start, end, x, root);
            euler.push_back(root);
        }
    }
    end[root] = euler.size() - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. taking inputs
    ll n, q;
    cin >> n >> q;
    vector<ll> val(n);
    rep(i, n) cin >> val[i];
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    // 2. making euler path;
    vector<ll> start(n), end(n);
    vector<ll> euler;
    computeByDfs(adj, euler, start, end, 0, -1);
    // for (ll x : euler)
    //     cout << x << " ";
    // 3. Making the sorted tree
    vector<vector<ll>> sortedTree(n);
    rep(i, n)
    {
        set<ll> st;
        for (ll j = start[i]; j <= end[i]; j++)
        {
            st.insert(euler[j]);
            // sortedTree[i].insert(euler[j]);
        }
        for (auto x : st)
        {
            // cout << x << " ";
            sortedTree[i].push_back(val[x]);
        }
        sort(sortedTree[i].begin(), sortedTree[i].end());
        // cout << "\n";
    }
    // Flipping a subset of columns is like doing a bitwise XOR of some number K onto each row.We want rows X with X ^ K = all 0s or all 1s. This is the same as X = X ^ K ^ K = (all 0s or all 1s) ^ K, so we want to count rows that have opposite bits set.For example, if K = 1, then we count rows X = (00000...001, or 1111....110).
    // sort(sortedTree.begin(), sortedTree.end());

    // for (auto x : sortedTree)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     } 
    //     cout << "\n";
    // }
    // 4. aswering the query

    while (q--)
    {
        ll node, kth;
        cin >> node >> kth;
        ll sz = sortedTree[node - 1].size();
        cout << sortedTree[node - 1][sz - kth] br;
    }
    return 0;
}
