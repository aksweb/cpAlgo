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

int n, dleft;
vector<vector<int>> dp;
vector<int> a;
int solve(int ind, int dleft)
{
    if (ind >= n || dleft < 0)
        return 0;
    if (dleft == 0)
        return 1;

    if (dp[ind][dleft] != -1)
        return dp[ind][dleft];

    return dp[ind][dleft] = (solve(ind + 1, dleft - a[ind]) + solve(ind, dleft - a[ind]) + solve(ind + 1, dleft)) % MOD;
}
int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        cin >> n >> dleft;
        dp.assign(n, vector<int>(dleft + 1, -1));
        a.resize(n);
        rep(i, 0, n) cin >> a[i];
        cout << solve(0, dleft) << "\n";
    }
    return 0;
}