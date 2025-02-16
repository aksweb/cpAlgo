#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for (int &x : v)
            cin >> x;

        int ans = 0, fg = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > d and fg == 0)
            {
                ans++;
                fg = 1;
            }
            else if (fg == 1 && v[i] <= d)
            {
                fg = 0;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
