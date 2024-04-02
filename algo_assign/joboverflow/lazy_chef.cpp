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

int pred(ll m, ll x)
{
    if (m < x)
        return 0;
    else
        return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    char ch;
    cin >> n >> ch;
    string s;
    cin >> s;
    ll p1 = -1, p2 = -1;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == ch)
        {
            p1 = i;
            break;
        }
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == ch)
        {
            p2 = i;
            break;
        }
    }

    if (p1 == p2)
    {
        cout << 0;
        return 0;
    }
    else
    {
        ll ans = 0;
        ll bleft = 0, bright = 0;
        for (int i = p1; i <= p2; i++)
        {
            if (s[i] != ch)
            {
                if (i - p1 - bleft <= p2 - i)
                {
                    ans += i - p1 - bleft;
                    bleft++;
                }
             
                else
                {
                    ans += p2 - i;
                }
            }
        }
        cout << ans;
    }

    return 0;
}