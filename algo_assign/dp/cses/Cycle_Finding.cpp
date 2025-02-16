class Solution
{
private:
    vector<int> cycle;

    int detect(int src, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &p)
    {
        stack<pair<int, int>> st;
        st.push({src, -1});
        vis[src] = true;

        while (!st.empty())
        {
            int u = st.top().first;
            int parent = st.top().second;
            st.pop();

            for (int x : adj[u])
            {
                if (vis[x] && x != parent)
                {
                    // Cycle detected
                    cycle.clear(); // Clear previous cycle
                    int current = u;

                    // Backtrack to form the cycle
                    cycle.push_back(x);
                    while (current != x)
                    {
                        cycle.push_back(current);
                        current = p[current];
                    }
                    cycle.push_back(x); // Complete the cycle

                    return 1;
                }

                if (!vis[x])
                {
                    vis[x] = true;
                    p[x] = u;
                    st.push({x, u});
                }
            }
        }
        return 0;
    }

public:
    bool isCycle(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis, parent) == 1)
                {
                    // Print the detected cycle
                    cout << "Cycle found: ";
                    for (int node : cycle)
                    {
                        cout << node << " ";
                    }
                    cout << endl;
                    return true;
                }
            }
        }
        return false;
    }
};