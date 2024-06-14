// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define br << endl

vector<int> damage, limit, disp;
vector<vector<int>> dp;
int n, D;
int solver(int ind, int d)
{
    if (d <= 0)
        return 0;
    if (ind == n)
        return INT_MAX;
    if (dp[ind][d] != -1)
        return dp[ind][d];
    // int take = disp[ind] + solver(ind + 1, d - damage[ind]);
    int take = disp[ind] + solver(ind, d - damage[ind]);
    int not_take = solver(ind + 1, d);

    return dp[ind][d] = min(take, not_take);
}
int main()
{

    cin >> n >> D;
    damage.resize(n);
    limit.resize(n);
    disp.resize(n);

    rep(i, 0, n)
    {
        cin >> damage[i];
        cin >> limit[i];
        cin >> disp[i];
        D -= (limit[i] * damage[i]);
        if (D <= 0)
        {
            cout << 0 br;
            return 0;
        }
    }

    dp.assign(n + 1, vector<int>(D + 1, -1));
    cout << solver(0, D);
    return 0;
}