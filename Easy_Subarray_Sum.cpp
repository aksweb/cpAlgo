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
        int n;
        cin >> n;
        vector<int> v(n);
        int greaterZero = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] > 0 && greaterZero == -1)
                greaterZero = i;
        }
        if (greaterZero == -1)
        {
            cout << 0 br;
        }
        else
        {

            int lasr = greaterZero, sum = 0;
            for (int i = n - 1; i > greaterZero; i--)
            {
                if (v[i] > 0)
                {
                    lasr = i;
                    break;
                }
            }
            for (int i = greaterZero; i <= lasr; i++)
            {
                if (v[i] < 0)
                    sum++;
            }
            cout << sum br;
        }
    }

    return 0;
}