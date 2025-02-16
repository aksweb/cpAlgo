#include <bits/stdc++.h>
using namespace std;

vector<int> euler;      // Euler Tour array
vector<int> start, end; // Entry and exit times for each node
vector<vector<int>> tree;

void dfs(int node, int parent)
{
    start[node] = euler.size(); // Entry time
    euler.push_back(node);

    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node);
            euler.push_back(node); // Add node again when returning
        }
    }

    end[node] = euler.size() - 1; // Exit time
}

int main()
{
    int n; // Number of nodes
    cin >> n;
    tree.resize(n + 1);
    start.resize(n + 1);
    end.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);

    // Print Euler Tour
    for (int node : euler)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

