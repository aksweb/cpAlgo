// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll MOD = 1e9 + 7;

// question rd k l
// constraits
// consider tc
// isse achha approach nhi melega bhai.

// Ye kab tk likhoge
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

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
    string a, b;
    cin >> a >> b;
    ll p = 0, q = 0;
    while (p != a.size() && q != b.size())
    {
        if (a[p] == b[q])
        {
            cout << a[p] << " ";
            p++;
            q++;
        }
        else
        {
            cout << "-" << a[p] << " ";
            p++;
        }
    }
    while (q != b.size())
    {
        cout << "+" << b[q] << " ";
        q++;
    }

    return 0;
}
