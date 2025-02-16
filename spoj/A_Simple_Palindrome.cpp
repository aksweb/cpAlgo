#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        char arr[5] = {'a', 'e', 'i', 'o', 'u'};
        int i = 0;
        string ans = "";
        int fg = 0;
        int step = 1;
        while (i < n)
        {
            // if (fg == 0)
            // {
            if (step = n)
            {
                step = 1;
            }
            int temp = 0;
            for (int j = 1; j <= 5 && (i + j <= n); j += step)
            {
                ans += arr[j - 1];
                temp++;
            }
            i += temp;
            fg = 1;
            step++;
            // }
            // else
            // {
            //     if (step = n)
            //     {
            //         step = 1;
            //     }
            //     for (int j = 0; j < 5 && (i + j < n); j += step)
            //     {
            //         ans += arr[4 - j];
            //     }
            //     i += 5;
            //     fg = 0;
            //     step++;
            // }
        }
        cout << ans << endl;
    }
    return 0;
}
