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
    int _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;

        string s;
        cin >> s;
        int fg = 0, c1 = 0, c2 = 0;
        // checking 1 section
        rep(i, 0, n)
        {
            if ((s[i] == '1') && (fg == 0))
            {
                c1++;
                fg = 1;
            }
            else if (s[i] == '0')
            {
                fg = 0;
            }
        }
        fg = 0;
        rep(i, 0, n)
        {
            if ((s[i] == '0') && (fg == 0))
            {
                c2++;
                fg = 1;
            }
            else if (s[i] == '1')
            {
                fg = 0;
            }
        }
        cout << min(c1, c2) br;
    }
}