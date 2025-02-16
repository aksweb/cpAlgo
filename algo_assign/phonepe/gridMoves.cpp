#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br '\n'
#define rep(i, n) for (ll i = 0; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, m;
    cin >> n >> m;

    while (n > 0 || m > 0)
    {
        if (n > m)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n -= m;
            }
        }
        else
        {
            if (m % 2 == 0)
            {
                m /= 2;
            }
            else
            {
                m -= n;
            }
        }
    }
    cout << ((n == 1 && m == 1) ? "Yes\n" : "No\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
