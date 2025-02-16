// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int _;
    cin >> _;

    while (_--)
    {
        int N;
        cin >> N;

        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < N - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for (int u = 1; u <= N; ++u)
        {
            int indegree = adj[u].size();

            if (indegree == 1)
            {
                ans += 3;
            }
            else
            {
                ans += 2;
            }
        }

        cout << ans br;
    }

    return 0;
}
