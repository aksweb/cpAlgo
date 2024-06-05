#include <iostream>
#include <vector>
#include <numeric>

#define MOD 1000000007

using namespace std;

// Function to compute the beauty for each value of K and store in dp
void compute_beauties(vector<vector<int>> &dp, int maxN, int maxK)
{
    for (int k = 1; k <= maxK; ++k)
    {
        for (int n = 1; n <= maxN; ++n)
        {
            dp[n][k] = dp[n - 1][k] * k % MOD;
            if (k > 1)
            {
                dp[n][k] = (dp[n][k] + dp[n - 1][k - 1]) % MOD;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    int maxN = 0, maxK = 0;
    vector<pair<int, int>> queries(T);

    for (int i = 0; i < T; ++i)
    {
        int N, K;
        cin >> N >> K;
        queries[i] = {N, K};
        maxN = max(maxN, N);
        maxK = max(maxK, K);
    }

    vector<vector<int>> dp(maxN + 1, vector<int>(maxK + 1, 0));
    compute_beauties(dp, maxN, maxK);

    for (const auto &query : queries)
    {
        int N = query.first;
        int K = query.second;
        cout << dp[N][K] << endl;
    }

    return 0;
}
