class Graph
{

public:
    bool bfs(int src, vector<int> adj[], vector<bool> vis)
    {
        int V = adj->size();
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = true;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto near : adj[node])
            {
                if (!vis[near])
                {
                    vis[near] = true;
                    q.push({near, node});
                }
                else if (near != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[])
    {
        // Write your code here.

        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (bfs(i, adj, vis))
                return true;
        }
        return false;
    }
};