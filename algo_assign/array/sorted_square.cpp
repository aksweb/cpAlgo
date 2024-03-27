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

bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// Code Begins Here
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int pos = -1;
    rep(i, n)
    {
        cin >> a[i];
        if (a[i] < 0)
            pos = i;
    }
    if (pos != -1)
    {
        int l = pos;
        int r = pos + 1;
        while (l >= 0 || r < n)
        {
            if (l >= 0 && r < n)
            {
                if (abs(a[l]) >= abs(a[r]))
                {
                    cout << a[r] * a[r] << " ";
                    r++;
                }
                else
                {
                    cout << a[l] * a[l] << " ";
                    l--;
                }
            }
            else
            {
                if (l < 0)
                {
                    cout << a[r] * a[r] << " ";
                    r++;
                }
                else
                {
                    cout << a[l] * a[l] << " ";
                    l--;
                }
            }
        }
    }
    else
    {
        rep(i, n){
            cout << a[i] * a[i] << " ";
            
        } 
    }

    return 0;
}
