#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)

ll helper(const string &s)
{
    ll w = 0;
    for (char ch : s)
    {
        w += (ch - 'a' + 1);
    }
    return w;
}

ll dfs(ll mask, ll budgetLeft, const vector<ll> &w, const vector<ll> &cost, const vector<ll> &solve, unordered_map<ll, unordered_map<ll, ll>> &memo)
{
    if (memo[mask].count(budgetLeft))
        return memo[mask][budgetLeft];

    ll maxWorth = 0;
    ll sz = w.size();
    for (ll i = 0; i < sz; i++)
    {
        ll bit = (1 << i);
        if ((mask & bit) == 0)
        {
            if ((mask & solve[i]) != 0)
                continue;

            if (budgetLeft < cost[i])
                continue;
            maxWorth = max(maxWorth, w[i] + dfs(mask | bit, budgetLeft - cost[i], w, cost, solve, memo));
        }
    }

    return memo[mask][budgetLeft] = maxWorth;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<string> str(n);
    vector<ll> cost(n);
    unordered_map<string, ll> mp;
    vector<ll> w(n);

    rep(i, n)
    {
        cin >> str[i];
        mp[str[i]] = i;
    }

    rep(i, n)
    {
        cin >> cost[i];
        w[i] = helper(str[i]);
    }

    vector<ll> solve(n, 0);

    rep(i, m)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (mp.find(s1) == mp.end() || mp.find(s2) == mp.end())
        {
            cerr << "Error: Contradictory string not found in input set\n";
            return -1;
        }

        ll idx1 = mp[s1], idx2 = mp[s2];
        solve[idx1] |= (1 << idx2);
        solve[idx2] |= (1 << idx1);
    }

    ll budget;
    cin >> budget;
    unordered_map<ll, unordered_map<ll, ll>> memo;
    ll maxWorth = dfs(0, budget, w, cost, solve, memo);

    cout << maxWorth << endl;
    return 0;
}
