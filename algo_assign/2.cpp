// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    vector<int> sum;
    map<int, int> freq;
    rep(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            int s = a[i] + a[j];
            freq[]
            // sum.push_back(a[i] + a[j]);
        }
    }
    sort(a, a + n);
    if (n == 3)
    {
        if (a[0] + a[1] > a[2])
        {
            cout << 1;
        }
        else
            cout << 0;
        return 0;
    }
    int i = 0;
    ll ans = 0;
    while (i <= n - 3)
    {
        int j = i + 1;
        while (j <= n - 2)
        {
            if (a[i] + a[j] > a[j + 1])
                ans++;
            j++;
        }
        i++;
    }
    cout << ans;
    return 0;
}
