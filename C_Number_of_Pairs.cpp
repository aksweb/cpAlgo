#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto low = lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
            auto high = upper_bound(a.begin() + i + 1, a.end(), r - a[i]);
            ans += high - low;
        }
        cout << ans << endl;
    }
    return 0;
}
