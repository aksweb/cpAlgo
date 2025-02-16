#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while (test--)
    {
        long long int n, behennchod;
        cin >> n >> behennchod;
        long long int a[n], b[n];
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        if (behennchod == 0)
        {
            cout << 0 br;
            continue;
        }
        long long int total = 0;
        vector<long long int> p;
        long long int ans = 0;
        rep(i, n)
        {
            p.push_back(a[i] * b[i]);
        }

        sort(p.begin(), p.end());
        for (long long int i = n - 1; i >= 0 && behennchod > 0; i--)
        {
            behennchod -= p[i];
            ans++;
        }
        if (behennchod <= 0)
            cout << ans br;
        else
            cout << -1 br;
    }

    return 0;
}