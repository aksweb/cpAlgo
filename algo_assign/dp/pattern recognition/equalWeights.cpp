#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % 2 == 1) // cant partition in two with equal sums.
    {
        cout << "NO\n";
        return;
    }
    // Dp[i][j] =  1, if we can use a subset of the first i elements of the array to make the sum equal to j.
    // Dp[i][j] = 0, otherwise.
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1; // base case
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i - 1][j] == 0)
                continue;
            dp[i][j] = 1;
            if (j + v[i] <= sum)
                dp[i][j + v[i]] = 1;
        }
    }
    int req = sum / 2;
    if (dp[n][req] == 1) // sum of each partition should be (total sum)/2 for both of them to be equal.
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}