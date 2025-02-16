// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

ll r, c, k;
// Code Begins Here
ll solve(vector<vector<ll>> &a, vector<vector<ll>> &dp(r, vector<ll>(c, -1)), ll i, ll j)
{
    if (i == r - 1 && j == c - 1)
        return 0;
    if (a[i][j] == 1 && k <= 0)
        return -1;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll op1 = 0, op2=0;
    if(i<r && j<c){
        if()
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;
    ll a[r][c];
    rep(i, r)
    {
        rep(j, c) cin >> a[i];
    }
    vector<vector<ll>> dp(r, vector<ll>(c, -1));
    solve(a, dp, 0, 0);
    cout << dp[r - 1][c - 1];

    return 0;
}
