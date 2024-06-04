// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

int n, m;
string a, b;
vector<vector<int>> dp;

int solve(int i, int j)
{
    if (i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + solve(i + 1, j + 1);
    }

    return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
}
int main()
{
    cin >> a >> b;
    n = a.length();
    m = b.length();
    dp.assign(n, vector<int>(m, -1));
    cout << solve(0, 0);
    return 0;
}