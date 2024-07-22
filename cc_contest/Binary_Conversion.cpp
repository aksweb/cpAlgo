#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;

        ll za = 0, zb = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                za++;
            if (t[i] == '0')
                zb++;
        }
        if (za != zb)
        {
            cout << "NO\n";
        }
        else
        {
            ll diff = 0;
            vector<ll> pos;
            vector<int> ones;
            vector<int> zero;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                {
                    if (s[i] == '0')
                        ones.push_back(i);
                    else
                        zero.push_back(i);

                    diff++;
                }
            }
            reverse(zero.begin(), zero.end());
            int sz = zero.size();
            ll mxSwaps = 0;
            for (ll i = 0; i < sz; i++)
            {
                mxSwaps += abs(ones[i] - zero[i]);
            }
            if ( k <= mxSwaps || diff==0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
