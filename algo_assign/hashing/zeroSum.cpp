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

    int n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, int> ump;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vector<ll> prefix(n, 0);
    prefix[0] = a[0];
    ump[prefix[0]]++;
    if (prefix[0] == 0)
    {
        cout << "YES" br;
        return 0;
    }
    bool fg = 0;
    rep(i, 1, n)
    {
        prefix[i] = prefix[i - 1] + a[i];
        ll temp = prefix[i];

        if (ump[temp] || temp == 0)
        {

            cout << "YES" br;
            fg = 1;
            break;
        }
        ump[temp]++;
    }
    if (fg == 0)
        cout << "NO" br;

    return 0;
}
