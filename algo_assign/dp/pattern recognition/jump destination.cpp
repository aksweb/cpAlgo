// TSETEN
// SDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

vector<int> jumps;
vector<vector<int>> dp;
int n, dleft;

bool solve(int dleft, int ind)
{
    if (dleft == 0)
        return true;
    if (ind >= n || dleft < 0)
        return false;
    if (dp[ind][dleft] != -1)
        return dp[ind][dleft];
    bool take = solve(dleft - jumps[ind], ind + 1);
    bool not_take = solve(dleft, ind + 1);
    return dp[ind][dleft] = take || not_take;
}
int main()
{
    int _;
    cin >> _;
    while (_--)
    {

        cin >> n >> dleft;
        jumps.resize(n + 1);
        dp.assign(n + 1, vector<int>(dleft + 1, -1));

        rep(i, 0, n) cin >> jumps[i];
        // int ans = solve(dleft, 0);
        // cout << ans br;
        if (solve(dleft, 0))
            cout
                << "YES" br;
        else
            cout << "NO" br;
    }
    return 0;
}