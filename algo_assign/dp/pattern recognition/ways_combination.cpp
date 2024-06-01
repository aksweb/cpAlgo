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

vector<int> heights;
vector<vector<int>> dp;
int n, dleft;

int main()
{
    int _;
    cin >> _;
    while (_--)
    {

        cin >> n;
        heights.resize(n + 1);
        dp.assign(n + 1, vector<int>(dleft + 1, -1));

        rep(i, 0, n) cin >> heights[i];
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