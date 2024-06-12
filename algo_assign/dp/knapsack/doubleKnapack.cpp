// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// vector<int> dp;
vector<vector<vector<int>>> dp;
int N, V;
vector<int> weights, vol;

int solver(int i, int v1, int v2, int w1, int w2)
{
    // base case
    if (i == N) 
        return abs(w1 - w2);
    if (v1 < 0 || v2 < 0)
        return INT_MAX;

    // memoization
    if (dp[i][v1][v2] != -1)
        return dp[i][v1][v2];

    // transition
    int put1 = INT_MAX;
    if (v1 - vol[i] >= 0)
        put1 = min(put1, solver(i + 1, v1 - vol[i], v2, w1 + weights[i], w2));

    int put2 = INT_MAX;
    if (v2 - vol[i] >= 0)
        put2 = min(put2, solver(i + 1, v1, v2 - vol[i], w1, w2 + weights[i]));

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
    if (result == INT_MAX)
        cout << -1;
    else
        cout << result;

    return 0;
}
