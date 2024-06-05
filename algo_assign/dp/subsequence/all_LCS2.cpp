#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

int n, m;
string a, b;
vector<vector<int>> dp;

// Explanation of the Modifications : Using a set to Collect All Possible LCS Strings :
//     The function make_string now returns a set<string>, which collects all possible LCS strings without duplicates.Recursive Cases Handling :

//     When a[i] == b[j],
//     add the current character a[i] to all LCS strings obtained from the recursive call make_string(i + 1, j + 1).
//     When the values in the dp table are equal(dp[i + 1][j] == dp[i][j + 1]),
//     both paths should be explored,
//     so we recursively call make_string(i + 1, j) and make_string(i, j + 1) and merge the results.

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

set<string> make_string(int i, int j)
{
    if (i >= n || j >= m)
    {
        return {""};
    }

    if (a[i] == b[j])
    {
        set<string> temp = make_string(i + 1, j + 1);
        set<string> result;
        for (const string &s : temp)
        {
            result.insert(a[i] + s);
        }
        return result;
    }

    set<string> result;
    if (dp[i + 1][j] >= dp[i][j + 1])
    {
        set<string> temp = make_string(i + 1, j);
        result.insert(temp.begin(), temp.end());
    }
    if (dp[i + 1][j] <= dp[i][j + 1])
    {
        set<string> temp = make_string(i, j + 1);
        result.insert(temp.begin(), temp.end());
    }

    return result;
}

int main()
{
    cin >> a >> b;
    n = a.length();
    m = b.length();
    dp.assign(n + 1, vector<int>(m + 1, -1));
    make_dp(0, 0);

    set<string> all_lcs = make_string(0, 0);
    for (const string &lcs : all_lcs)
    {
        string rev_lcs = lcs;
        // reverse(rev_lcs.begin(), rev_lcs.end());
        cout << rev_lcs br;
    }

    return 0;
}
