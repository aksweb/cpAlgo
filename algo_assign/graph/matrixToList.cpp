// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// isse achha approach nhi melega.
// question r k l
// cnts
// tcs

// comparator
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first >
               b.first;
}

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> list(n);

    rep(i, n)
    {
        rep(j, n)
        {
            ll t;
            cin >> t;
            if (t)
                list[i].push_back(j+1);
        }
    }
    int cnt = 1;
    for (auto x : list)
    {
        cout << cnt++ << ": ";
        for (auto xx : x)
            cout << xx << " ";
        cout << "\n";
    }

    return 0;
}
