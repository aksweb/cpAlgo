#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            st.insert(x);
        }
        if (st.size() > 2)
        {
            cout << "NO\n";
            continue;
        }
        int fg = 0;
        for (auto x : st)
        {
            if (x == 0)
                fg = 1;
        }
        if (fg == 1 || st.size() == 1)
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
