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

// vector<int> dp;
vector<vector<vector<int>>> dp;
vector<int> pro, fats, carb;
int P, F;
int n;

int solver(int ind, int p, int f)
{
    if (p <= 0 && f <= 0)
    {
        p = 0;
        f = 0;
        return 0;
    }
    if (ind == n && (p > 0 || f > 0))
        return INT_MAX;

    if (dp[ind][p][f] != 0)
        return dp[ind][p][f];

    int take = carb[ind] + solver(ind + 1, p - pro[ind], f - fats[ind]);
    int not_take = solver(ind + 1, p, f);
    int val = min(take, not_take);
    if (val = INT_MAX)
        return dp[ind][p][f] = -1;
    else
        return dp[ind][p][f] = val;
}

int main()
{
    cin >> P >> F;
    cin >> n;
    dp.assign(n, vector<vector<int>>(P + 1, vector<int>(F + 1, -1)));

    // dp.assign(n + 1, 0);
    pro.resize(n);
    fats.resize(n);
    carb.resize(n);
    rep(i, 0, n)
    {
        cin >> pro[i] >> fats[i] >> carb[i];
    }

    cout << solver(0, P, F);

    return 0;
}