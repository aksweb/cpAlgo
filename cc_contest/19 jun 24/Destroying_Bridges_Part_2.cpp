#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges.emplace_back(a[i] * a[j], i, j);
        }
    }

    sort(edges.begin(), edges.end(), greater<tuple<ll, int, int>>());

    vector<int> parent(n), rank(n, 0);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    };

    auto union_sets = [&](int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (rank[u] < rank[v])
                swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v])
                rank[u]++;
        }
    };

    ll total_cost = 0;
    for (const auto &edge : edges)
    {
        ll cost;
        int u, v;
        tie(cost, u, v) = edge;
        if (total_cost + cost > c)
            break;
        if (find(u) != find(v))
        {
            union_sets(u, v);
            total_cost += cost;
        }
    }

    unordered_set<int> unique_parents;
    for (int i = 0; i < n; i++)
    {
        unique_parents.insert(find(i));
    }

    cout << unique_parents.size() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
