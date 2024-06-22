#include <bits/stdc++.h>
using namespace std;

int N, F, P;
vector<int> pro, fats, carbs;
vector<vector<vector<int>>> dp;

int solver(int idx, int p, int f)
{
    if (p >= P && f >= F)
    {
        return 0;
    }
    if (idx == N)
    {
        return INT_MAX;
    }
    // Memoization
    if (dp[idx][p][f] != -1)
    {
        return dp[idx][p][f];
    }
    // Taking the current item
    int take = INT_MAX;
    int new_p = min(P, p + pro[idx]);
    int new_f = min(F, f + fats[idx]);
    int res_take = solver(idx + 1, new_p, new_f);
    if (res_take != INT_MAX)
    {
        take = res_take + carbs[idx];
    }
    // Not taking the current item
    int not_take = solver(idx + 1, p, f);
    // Storing the result in dp array
    return dp[idx][p][f] = min(take, not_take);
}

int main()
{
    cin >> P >> F >> N;
    dp.resize(N, vector<vector<int>>(P + 1, vector<int>(F + 1, -1)));

    pro.resize(N);
    fats.resize(N);
    carbs.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> pro[i] >> fats[i] >> carbs[i];
    }

    int result = solver(0, 0, 0);
    if (result == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
