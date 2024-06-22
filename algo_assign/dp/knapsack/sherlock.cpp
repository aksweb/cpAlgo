#include <bits/stdc++.h>
using namespace std;

int C, Z, O;
vector<vector<vector<int>>> dp;
vector<string> v;

pair<int, int> help(int idx)
{
    int zc = 0;
    for (char ch : v[idx])
    {
        if (ch == '0')
            zc++;
    }
    return {zc, v[idx].size() - zc};
}
int solve(int z, int o, int idx)
{
    if (idx < 0)
        return 0;

    // mem
    if (dp[idx][z][o] != -1)
        return dp[idx][z][o];

    int take = -1;
    pair<int, int> cnt = help(idx);

    if (cnt.first <= z && cnt.second <= o)
    {
        take = solve(z - cnt.first, o - cnt.second, idx - 1) + 1;
    }
    int not_take = solve(z, o, idx - 1);

    return dp[idx][z][o] = max(take, not_take);
}
int main()
{
    cin >> C >> Z >> O;
    v.resize(C);
    dp.resize(C, vector<vector<int>>(Z + 1, vector<int>(O + 1, -1)));

    for (int i = 0; i < C; i++)
        cin >> v[i];

    cout << solve(Z, O, C - 1);

    return 0;
}