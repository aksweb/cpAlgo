// TSETEN RGIPT
// someDAY
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
#define rloop(i, a, b) for (ll i = a; i > b; i--)
#define trav(a, b) for (auto a : b)
#define MOD2 629421302
#define INF 1000000000000000000

ll helper(const string &s)
{
    ll w = 0;
    for (char ch : s)
    {
        w += (ch - 'a' + 1);
    }
    return w;
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
        ll idx1 = mp[s1], idx2 = mp[s2];
        solve[idx1] |= (1 << idx2);
        solve[idx2] |= (1 << idx1);
    }

    ll budget;
    cin >> budget;
    ll msk = (1 << n);
    vector<ll> dp(msk, 0);
    vector<ll> dpCost(msk, 0);
    ll maxWorth = 0;
    for (ll mask = 0; mask < msk; mask++)
    {
        for (ll i = 0; i < n; i++)
        {
            ll bit = (1 << i);
            if ((mask & bit) == 0)
            {
                ll newMask = mask | bit;

                if ((mask & solve[i]) != 0)
                    continue;

                if (dpCost[mask] + cost[i] > budget)
                    continue;

                dp[newMask] = max(dp[newMask], dp[mask] + w[i]);
                dpCost[newMask] = dpCost[mask] + cost[i];
                maxWorth = max(maxWorth, dp[newMask]);
            }
        }
    }

    cout << maxWorth << endl;
    return 0;
}
