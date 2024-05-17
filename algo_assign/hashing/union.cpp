// TESTEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<ll, int> ump;

    rep(i, 0, n + m)
    {
        ll temp;
        cin >> temp;
        ump[temp]++;
    }

    for (auto &x : ump)
    {
        if (x.second != 0)
            cout << x.first << " ";
    }

    return 0;
}
