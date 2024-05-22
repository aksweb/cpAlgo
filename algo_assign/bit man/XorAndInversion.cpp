#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int count = 0;
    unordered_map<int, int> ump;

    rep(i, 0, n)
    {
        ump[31 - __builtin_clz(a[i])]++;
    }
    rep(i, 0, ump.size())
    {
        if (ump[i] > 1)
        {
            count += (ump[i] * (ump[i] - 1)) / 2; // nc2
        }
    }
    cout << count;
    return 0;
}
