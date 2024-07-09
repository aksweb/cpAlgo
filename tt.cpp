
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    int test;
    cin >> test;

    while (test--)
    {
        ll lund;
        cin >> lund;
        vector<ll> bhosideke(lund);
        for (ll i = 0; i < lund; i++)
            cin >> bhosideke[i];
        sort(bhosideke.begin(), bhosideke.end());
        int fg = 0;
        for (int i = 1; i <= lund; i++)
        {
            if (i - bhosideke[i - 1] < 0)
            {
                fg = 1;
                // cout << i << " " << bhosideke[i-1] << endl;
                break;
            }
        }
        if (fg == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}