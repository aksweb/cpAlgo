
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll _;
    cin >> _;
    while (_--)
    {
        string s;
        cin >> s;
        bool fg = 0;
        ll n = s.size();
        for (ll i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
            {

                cout << "NO" br;
                fg = 1;
                break;
            }
        }
        if (!fg)
            cout << "YES" br;
    }
    return 0;
}
