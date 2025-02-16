#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        int count = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans <= k)
                count++;
        }
        cout << ans << endl;
    }

    return 0;
}
