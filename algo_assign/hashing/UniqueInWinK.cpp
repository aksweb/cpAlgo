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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    rep(i, 0, n - k + 1)
    {
        // cout << a[i] << " ";
        vector<int> temp(101, 0);
        for (int j = i; j < (i + k); j++)
        {
            temp[a[j]]++;
        }
        ll ans = 0;
        for (int j = 0; j < 101; j++)
        {
            if (temp[j] == 1)
                ans++;
        }
        cout << ans << " ";
    }
    return 0;
}
