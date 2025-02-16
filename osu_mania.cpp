// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        char arr[n][4];
        vector<ll> ans;

        rep(i, n)
        {
            rep(j, 4)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '#')
                {
                    ans.push_back(j + 1);
                }
            }
        }

        for (ll i = n - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout br;
    }

    return 0;
}