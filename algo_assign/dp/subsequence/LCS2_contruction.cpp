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

int make_dp(int i, int j)
{
    if (i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + make_dp(i + 1, j + 1);
    }

    return dp[i][j] = max(make_dp(i + 1, j), make_dp(i, j + 1));
}
string make_string(int i, int j)
{
    if (i >= n || j >= m)
    {
        return "";
    }
    if (a[i] == b[j])
    {
        return make_string(i + 1, j + 1) + a[i];
    }
    if (dp[i + 1][j] > dp[i][j + 1])
    {
        return make_string(i + 1, j);
    }
    else if (dp[i + 1][j] < dp[i][j + 1])
    {
        return make_string(i, j + 1);
    }
    else // if both dp[i + 1][j] == dp[i][j + 1], prefer the character in b
    {
        return make_string(i + 1, j);
    }
}
int main()
{
    cin >> a >> b;
    n = a.length();
    m = b.length();
    dp.assign(n + 1, vector<int>(m + 1, -1));
    make_dp(0, 0);
    string ans = make_string(0, 0);
    reverse(ans.begin(), ans.end());
    cout << ans br;
    return 0;
}