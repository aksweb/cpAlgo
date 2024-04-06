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

int pred(ll m, ll b)
{
    if (m < b)
    {
        return 0;
        cout << m << " ";
    }
    else
        return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int s = a[i] + a[j];
            ll l = 0, r = n;
            while (l + 1 < r)
            {
                ll m = (l + r) / 2;
                if (pred(a[m], s) == 0)
                {
                    l = m;
                    if (l != i && l != j)
                        ans++;
                }
                else
                    r = m;
            }
            
        }
    }
    cout << ans;
    return 0;
}
