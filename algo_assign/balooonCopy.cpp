#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll w, y;
// DP table: dp[n][m][last][cons]
// Initialize to -1 (uncomputed states)
vector<vector<vector<vector<ll>>>> dp;

ll now(ll n, ll m, ll last, ll cons)
{
    // Base case: All balloons placed successfully
    if (n == 0 && m == 0)
    {
        return 1;
    }

    // Invalid state
    if (n < 0 || m < 0 || (last == 0 && cons > w) || (last == 1 && cons > y))
        return 0;

    // Check if already computed
    if (dp[n][m][last][cons] != -1)
        return dp[n][m][last][cons];

    ll ans = 0;

    // If the last balloon was white
    if (last == 0)
    {
        // Add another white balloon if constraints allow
        if (n > 0 && cons < w)
        {
            ans += now(n - 1, m, 0, cons + 1);
        }
        // Switch to yellow balloon
        if (m > 0)
        {
            ans += now(n, m - 1, 1, 1);
        }
    }

    // If the last balloon was yellow
    if (last == 1)
    {
        // Add another yellow balloon if constraints allow
        if (m > 0 && cons < y)
        {
            ans += now(n, m - 1, 1, cons + 1);
        }
        // Switch to white balloon
        if (n > 0)
        {
            ans += now(n - 1, m, 0, 1);
        }
    }

    // Store the result in the DP table
    return dp[n][m][last][cons] = ans;
}

int main()
{
    ll n, m;
    cin >> n >> m >> w >> y;

    // Initialize the DP table
    dp.resize(n + 1, vector<vector<vector<ll>>>(m + 1, vector<vector<ll>>(2, vector<ll>(max(w, y) + 1, -1))));

    // Start with a white balloon
    ll ans = now(n - 1, m, 0, 1);
    // Start with a yellow balloon
    ans += now(n, m - 1, 1, 1);

    cout << ans << endl;

    return 0;
}
