// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

// Code Begins Here

// lcs code
int lcs(string a, string b)
{
    int n = a.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
int main()
{
    char16_t
        ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        cout << lcs(a, b) br;
    }

    return 0;
}
