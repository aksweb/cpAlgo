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

int n, cap;
vector<vector<int>> dp;
vector<int> weights;
vector<int> profits;

int solver(int ind, int w)
{
    if (ind >= n || w <= 0)
    {
        return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int take = INT_MIN;
    if (w - weights[ind] >= 0)
    {
        take = profits[ind] + solver(ind + 1, w - weights[ind]);
    }
    int not_take = solver(ind + 1, w);
    return dp[ind][w] = max(take, not_take);
}
int main()
{
    cin >> n >> cap;
    dp.assign(n + 1, vector<int>(cap + 1, -1));
    weights.resize(n);
    profits.resize(n);

    rep(i, 0, n)
    {
        cin >> weights[i];
        cin >> profits[i];
    }
    cout << solver(0, cap);

    return 0;
}