// TSETEN RGIPT
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    long long minSecond = INT_MAX;
    vector<pair<long long, long long>> c;
    bool foundFlag = false;
    long long index = 0;
    long long lastFirst = INT_MIN;

    for (long long i = 0; i < n; i++)
    {
        if (a[i].second <= minSecond && a[i].first > lastFirst)
        {
            c.push_back({a[i].first, a[i].second});
            minSecond = min(minSecond, a[i].second);
            if (i == n - 1)
                foundFlag = true;
            index = i;
            lastFirst = a[i].first;
        }
    }

    minSecond = a[n - 1].second;
    vector<pair<long long, long long>> c2;
    bool foundFlag2 = true;

    for (long long i = n - 1; i > index; i--)
    {
        if (a[i].second <= minSecond && ((foundFlag2 && (a[i].first > lastFirst)) || a[i].first < lastFirst))
        {
            c2.push_back({a[i].first, a[i].second});
            minSecond = min(a[i].second, minSecond);
            lastFirst = a[i].first;
            foundFlag2 = false;
        }
    }

    reverse(c2.begin(), c2.end());
    for (long long i = 0; i < c2.size(); i++)
    {
        c.push_back(c2[i]);
    }

    double ans = 0;
    long long sz = c.size() - 1;
    for (long long i = 0; i < ; i++)
    {
        long long x = c[i].first;
        long long y = c[i].second;
        long long z = c[i + 1].first;
        long long w = c[i + 1].second;

        double val = sqrt(pow(static_cast<double>(z - x), 2) + pow(static_cast<double>(w - y), 2));
        ans += val;
    }

    cout << static_cast<long long>(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
