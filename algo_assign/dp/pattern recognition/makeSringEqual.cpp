#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> dp;

int solve(int i, int j, string &s, string &t)
{
    if (i == n)
        return m - j;
    if (j == m)
        return n - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = INT_MAX;
    if (s[i] == t[j])
    {
        take = solve(i + 1, j + 1, s, t);
    }
    int del = solve(i + 1, j, s, t) + 1;
    int rep = solve(i + 1, j + 1, s, t) + 1;
    int add = solve(i, j + 1, s, t) + 1;
    return dp[i][j] = min({take, del, rep, add});
}
int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        cin >> n >> m;
        dp.assign(n, vector<int>(m, -1));
        string s, t;
        cin >> s >> t;
        cout << solve(0, 0, s, t) << "\n";
    }
    return 0;
}