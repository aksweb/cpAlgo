// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int pred(ll m, ll h)
{

    if (m > h)
        return 0;
    else
        return 1;
}

void solve()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < N; ++i)
            cin >> B[i];

        vector<vector<int>> dp(N, vector<int>(2, 0)); 

        for (int i = 3; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                for (int k = j + 1; k < i; ++k)
                {
                    if (A[i] <= A[j] + A[k])
                        dp[i][0] = max(dp[i][0], dp[j][0] + dp[k][0] + 1);
                    if (A[i] <= B[j] + A[k])
                        dp[i][0] = max(dp[i][0], dp[j][1] + dp[k][0] + 1);
                    if (A[i] <= A[j] + B[k])
                        dp[i][0] = max(dp[i][0], dp[j][0] + dp[k][1] + 1);
                    if (A[i] <= B[j] + B[k])
                        dp[i][0] = max(dp[i][0], dp[j][1] + dp[k][1] + 1);

                    if (B[i] <= A[j] + A[k])
                        dp[i][1] = max(dp[i][1], dp[j][0] + dp[k][0] + 1);
                    if (B[i] <= B[j] + A[k])
                        dp[i][1] = max(dp[i][1], dp[j][1] + dp[k][0] + 1);
                    if (B[i] <= A[j] + B[k])
                        dp[i][1] = max(dp[i][1], dp[j][0] + dp[k][1] + 1);
                    if (B[i] <= B[j] + B[k])
                        dp[i][1] = max(dp[i][1], dp[j][1] + dp[k][1] + 1);
                }
            }
        }

        cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
