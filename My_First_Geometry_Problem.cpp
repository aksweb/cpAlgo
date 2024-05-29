// TSETEN
// SDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int count = 0;
        for (char ch : s)
        {
            if (ch == '1')
                count++;
        }

        if (count == 3)
        {
            cout << 231 br;
        }
        else if (count == 4)
        {
            cout << 441 br;
        }
        else if (count == 1)
        {
            cout << 11 br;
        }
        else if (count == 2)
        {
            // Correct conditions to check pairs of directions
            if ((s[0] == '1' && s[2] == '1') ||
                (s[0] == '1' && s[3] == '1') ||
                (s[1] == '1' && s[2] == '1') ||
                (s[1] == '1' && s[3] == '1'))
            {
                cout << 121 br;
            }
            else
            {
                cout << 21 br;
            }
        }
    }

    return 0;
}