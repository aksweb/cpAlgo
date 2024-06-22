// ABHISHEKH786 RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define gcd __gcd
#define br << endl
// #define cin cin>>
// #define cout cout<<
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ss second
#define ff first
#define mkp make_pair
#define vi vector<int>
#define vl vector<ll>
#define all(v) v.begin(), v.end()
// #define size(v) v.size()
#define pb push_back
#define si set<int>
#define sl set<ll>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repint(i, n) for (int i = 0; i < n; i++)

#define repi(i, m, n) for (int i = m; i < n; i++)

#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, a, b) for (ll i = a; i > b; i--)
#define trav(a, b) for (auto a : b)
#define MOD 1000000007
#define MOD2 629421302
#define INF 1000000000000000000

ll solve(int n, vector<ll> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != -1)
        return dp[n];

    ll ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        ans += solve(n - i, dp);
        ans %= MOD;
    }

    return dp[n] = ans;
}
int main()
{

    ll sum;
    cin >> sum;
    vector<ll> dp(sum + 1, -1);

    dp[0] = 1;
    dp[1] = 1;
    if (sum <= 1)
    {
        cout << dp[sum];
        return 0;
    }

    cout << solve(sum, dp);

    // cout << dp[sum];

    return 0;
}