// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
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

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first >
               b.first;
}

int pred(ll m, ll a, ll b, ll prevSum)
{
    // cout << "m: " << m br;
    ll currSum = (m * (m + 1) / 2) - prevSum;
    if (currSum >= a && currSum <= b)
        return 2;
    else if (currSum < a)
        return 0;
    else
        return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll q, l, r;
    cin >> q >> l >> r;
    ll prevSum = ((l - 1) * l) / 2;

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        int fg = 0;
        ll low = l - 1, high = r + 1;
        while (low + 1 < high)
        {

            ll m = (low + high) / 2;
            ll val = pred(m, a, b, prevSum);

            if (val == 2)
            {
                fg = 1;
                cout << 1 br;
                break;
            }
            else if (val == 0)
                low = m;

            else
                high = m;
        }
        if (fg == 0)
            cout << 0 br;
    }

    return 0;
}
