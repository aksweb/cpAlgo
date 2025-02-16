// TSETEN RGIPT
// ΣDAY
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

int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s)
    {
        cnt[c - 'a']++;
    }
    string ans = "";
    int fg = 1;
    for (int i = 25; i >= 0; i--)
    {
        while (cnt[i] > 0 && fg == 1)
        {
            if (cnt[i] > 0)
            {
                if (cnt[i] > k)
                {
                    int temp = k;
                    while (temp--)
                    {
                        ans += 'a' + i;
                    }
                    cnt[i] -= k;
                }
                else
                {
                    while (cnt[i]--)
                    {
                        ans += 'a' + i;
                    }
                }
                if (cnt[i] > 0)
                {
                    fg = 0;
                    for (int j = 25; j >= 0; j--)
                    {
                        if (i != j)
                        {

                            if (cnt[j] > 0)
                            {
                                ans += 'a' + j;
                                fg = 1;
                                cnt[j]--;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans br;

    return 0;
}