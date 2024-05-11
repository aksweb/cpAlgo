
int bfs(int src, vector<vector<int>> &adj)
{
    int ans = 0;
    vector<bool> visited(adj.size(), false); // Mark all nodes as not visited
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (adj[node].size() == 1 && adj[adj[node]].size() == 2)
            ans += (depth / 4) - 1;
        else if ()
            // cout << depth << " "; // Print the depth of the current node
            visited[node] = true; // Mark the current node as visited
        for (auto v : adj[node])
        {
            if (!visited[v]) // Only push unvisited neighbors
            {
                q.push({v, depth + 1});
            }
        }
    }
    return ans;
}