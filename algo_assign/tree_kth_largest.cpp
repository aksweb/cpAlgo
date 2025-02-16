#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;        // Maximum number of vertices
vector<int> tree[MAXN];          // Adjacency list for the tree
vector<int> values;              // Values on the vertices
vector<int> euler;               // Euler tour array
int start[MAXN], endTime[MAXN];  // Start and end indices of subtrees
vector<int> sortedSubtree[MAXN]; // Sorted values for each subtree

// Perform DFS and record Euler tour
void dfs(int node, int parent)
{
    start[node] = euler.size();
    euler.push_back(node);
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node);
        }
    }
    endTime[node] = euler.size() - 1;
}

int main()
{
    int n, q;
    cin >> n >> q;

    values.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Perform DFS starting from root (node 1)
    dfs(1, -1);

    // Build sorted lists for each subtree
    for (int i = 1; i <= n; i++)
    {
        for (int j = start[i]; j <= endTime[i]; j++)
        {
            sortedSubtree[i].push_back(values[euler[j]]);
        }
        sort(sortedSubtree[i].begin(), sortedSubtree[i].end(), greater<int>()); // Descending order
    }

    // Answer queries
    while (q--)
    {
        int v, k;
        cin >> v >> k;
        if (k > sortedSubtree[v].size())
        {
            cout << -1 << endl; // Invalid query
        }
        else
        {
            cout << sortedSubtree[v][k - 1] << endl; // k-th largest
        }
    }

    return 0;
}
