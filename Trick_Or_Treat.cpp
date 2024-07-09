
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    int test;
    cin >> test;

    while (test--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        unordered_map<ll, ll> mpa, mpb;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mpa[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mpa[b[i]]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if()
        }
    }

    return 0;
}