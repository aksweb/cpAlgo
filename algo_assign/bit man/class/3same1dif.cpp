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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[10] = {3, 3, 3, 5, 5, 5, 7, 7, 7, 11};
    int ans = 0;
    int mask = 1;
    int count[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            if (a[i] & (1 << i))
            {
                cnt++;
            }
        }
        if (cnt % 3 != 0)
        {
            ans |= (1 << i);
        }
    }
    return 0;
}
