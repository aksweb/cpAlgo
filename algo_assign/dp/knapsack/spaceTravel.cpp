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

const int NINF = INT_MIN;
vector<int> G, M, V;
vector<vector<int>> dp;
vector<vector<int>> ans;

int n, f;

int solver(int ind, int currMass, vector<int> temp)
{
    if (currMass * G[ind] > T)
    {
        ans.push_back(temp);
        return 0;
    }
    if (ind == n)
        return NINF;

    int take = NINF;
    if ((M[ind] + currMass) * G[ind] <= T)
    {

        temp.push_back(V[ind]);
        take = V[ind] + solver(ind + 1, currMass + M[ind], temp);
        temp.pop_back();
    }
    int not_take = solver(ind + 1, currMass, temp);
    return dp[ind][currMass] = max(take, not_take);
}

int main()
{

    cin >> n >> T;
    G.resize(n);
    M.resize(n);
    V.resize(n);

    rep(i, 0, n)
    {
        cin >> G.[i];
        cin >> M.[i];
        cin >> V.[i];
    }

    dp.assign(n + 1, vector<int>(D + 1, -1));
    // cout << solver(0, D);
    return 0;
}