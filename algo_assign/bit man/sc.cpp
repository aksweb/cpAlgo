// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// Code Begins Here

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if (n <= 1)
        {
            cout << n br;
            continue;
        }
        ll ans = 0;
        ll rm = 0;
        rep(i, 0, n - 1)
        {
            if (s[i] == s[i + 1])
            {
                int count = 0;
                while (s[i] == s[i + 1])
                {
                    count++;
                    if (count > 2)
                        rm++;
                    i++;
                    // fg = 1;
                }
            }
        }
        if (s[n - 1] == s[n - 2])
            ans++;
        ans = n - rm;
        cout << ans << " " << n << " " << rm << " " br;
        // cout << ans br;
    }

    return 0;
}