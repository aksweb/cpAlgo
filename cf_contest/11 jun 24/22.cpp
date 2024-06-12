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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int best = 2;
        int mx = 0;

        for (int x = 2; x <= n; x++)
        {
            int sum = 0;
            for (int k = 1; k * x <= n; k++)
            {
                sum += k * x;
            }
            if (sum > mx)
            {
                mx = sum;
                best = x;
            }
        }

        cout << best br;
    }
    return 0;
}
