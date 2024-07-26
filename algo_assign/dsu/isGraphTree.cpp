class Solution
{
public:
    /////////////////////////////////////////////////
    vector<int> parent;
    vector<int> rank;
    int n; // Number of nodes

    // Default constructor
    Solution() {}

    // Initialize with the number of nodes
    void initialize(int n)
    {
        this->n = n;
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    /////////////////////////////////////////////////

    int findPar(int u)
    {
        if (parent[u] != u)
            parent[u] = findPar(parent[u]);
        return parent[u];
    }
    bool doUnion(int u, int v)
    {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV)
            return false; // Cycle detected

        // Union by rank
        if (rank[parU] > rank[parV])
        {
            parent[parV] = parU;
        }
        else if (rank[parU] < rank[parV])
        {
            parent[parU] = parV;
        }
        else
        {
            parent[parV] = parU;
            rank[parU]++;
        }
        return true;
    }
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        initialize(n); // initialization
        if (m != n - 1)
            return 0; // A tree must have exactly N-1 edges

        for (const auto &edge : adj)
        {
            if (!doUnion(edge[0], edge[1]))
                return 0; // Cycle detected
        }

        // Ensure all nodes are connected (i.e., all nodes have the same root)
        int root = findPar(0);
        for (int i = 1; i < n; ++i)
        {
            if (findPar(i) != root)
                return 0; // Disconnected component
        }

        return 1; // No cycles and N-1 edges, all nodes connected
    }
};