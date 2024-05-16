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
            cout << n << endl;
            continue;
        }

        int count = 0;
        char prevChar = '\0';
        int consecutiveCount = 0;

        for (char c : s)
        {
            if (c == prevChar)
            {
                consecutiveCount++;
                if (consecutiveCount % 2 == 0)
                {
                    count++;
                }
            }
            else
            {
                consecutiveCount = 1;
            }
            prevChar = c;
        }

        cout << n - count br;
    }

    return 0;
}