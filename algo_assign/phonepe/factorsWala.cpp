#include <bits/stdc++.h>
using namespace std;

// Function to compute the minimum moves to reduce N to 0
int solve(int N, vector<int> &dp)
{
    if (N == 0)
        return 0;
    if (dp[N] != INT_MAX)
        return dp[N];

    // Option 1: Subtract 1
    int v1 = 1 + solve(N - 1, dp);

    // Option 2: Replace with max(a, b) for all valid factorizations
    int v2 = INT_MAX;
    for (int i = 2; i <= sqrt(N); ++i)
    {
        if (N % i == 0)
        {
            int reduced = max(i, N / i);
            v2 = min(v2, 1 + solve(reduced, dp));
        }
    }

    // Store the result and return
    dp[N] = min(v1, v2);
    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N + 1, INT_MAX);
    cout << solve(N, dp) << endl;
    return 0;
}
