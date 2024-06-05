#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll INF = 1e9;

int main()
{
    int _;
    cin >> _;

    while (_--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> spells(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> spells[i].first >> spells[i].second;
        }

        int mxst = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int st = spells[i].second * spells[j].first + spells[i].first * spells[j].second;
                mxst = max(mxst, st);
            }
        }

        cout << mxst << endl;
    }

    return 0;
}
