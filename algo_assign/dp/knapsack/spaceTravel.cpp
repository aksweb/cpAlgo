#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int NINF = INT_MIN;
vector<int> G, M, V;
vector<vector<ll>> dp;
vector<vector<int>> ans;

ll n, F;

ll solver(ll idx, ll currMass, vector<int> temp)
{
    if (idx == n)
    {
        ans.push_back(temp);
        return 0;
    }
    // memo
    if (dp[idx][currMass] != -1)
        return dp[idx][currMass];
    ll take = NINF;
    if ((M[idx] + currMass) * G[idx] <= F)
    {
        temp.push_back(idx + 1); // store the planet number
        take = V[idx] + solver(idx + 1, currMass + M[idx], temp);
        temp.pop_back();
    }
    ll not_take = solver(idx + 1, currMass, temp);
    return dp[idx][currMass] = max(take, not_take);
}

int main()
{
    cin >> n >> F;
    G.resize(n);
    M.resize(n);
    V.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> G[i] >> M[i] >> V[i];
    }

    dp.assign(n + 1, vector<ll>(F + 1, -1));
    vector<int> temp;
    solver(0, 0, temp);

    // Find the best solution
    ll maxVal = NINF;
    vector<int> bestAns;
    for (auto &a : ans)
    {
        ll currVal = 0;
        for (int planet : a)
        {
            currVal += V[planet - 1];
        }
        if (currVal > maxVal)
        {
            maxVal = currVal;
            bestAns = a;
        }
    }

    cout << bestAns.size() << endl;
    for (int planet : bestAns)
    {
        cout << planet << " ";
    }
    cout << endl;

    return 0;
}
