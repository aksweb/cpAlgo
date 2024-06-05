#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll INF = 1e9;

vector<vector<vector<int>>> dp;
int N, V;
vector<int> weights, vol;

int solver(int i, int v1, int v2, int w1, int w2)
{
    // Base case: If any compartment's volume is negative, return a high value
    if (v1 < 0 || v2 < 0)
        return INF;
    // Base case: If all items are considered, return the absolute difference in weights
    if (i == N)
        return abs(w1 - w2);

    // Memoization: Return the stored result if already computed
    if (dp[i][v1][v2] != -1)
        return dp[i][v1][v2];

    // Recursive case: Place the current item in the left compartment
    int put1 = solver(i + 1, v1 - vol[i], v2, w1 + weights[i], w2);
    // Recursive case: Place the current item in the right compartment
    int put2 = solver(i + 1, v1, v2 - vol[i], w1, w2 + weights[i]);

    // Store and return the minimum difference
    return dp[i][v1][v2] = min(put1, put2);
}

int main()
{
    cin >> N >> V;
    dp.assign(N + 1, vector<vector<int>>(V + 1, vector<int>(V + 1, -1)));
    weights.resize(N);
    vol.resize(N);

    rep(i, 0, N)
    {
        cin >> weights[i] >> vol[i];
    }

    int result = solver(0, V, V, 0, 0);
    if (result == INF)
        cout << -1;
    else
        cout << result;

    return 0;
}
