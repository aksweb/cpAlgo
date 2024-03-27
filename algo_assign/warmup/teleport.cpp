// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define ll long long int
#define br << endl
#define rep(i, n)              \
    for (ll i = 0; i < n; i++) \
    yy
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 998244353;

// question padh le bhai
// constraits bhi dekh lo plz..
// have trust on urself, jo tu kar rha hai best approach hai.
// sir jo dimag me test case aa raha hai uspe chala ke dekh lo ek bar
// no cheating

// Function to calculate the greatest common divisor
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// Code Begins Here

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    ll xx = x, yy = y;
    x = min(xx, yy);
    y = max(xx, yy);
    ll l = min(a, b);
    ll r = max(a, b);

    if (x <= l && r <= y)
    {
        ans = l - x + y - r;
    }
    else if (x <= l && r > y)
    {
        ll a1 = y - x;
        ll a2 = l - x + r - y;
        ans = min(a1, a2);
    }
    else if (l < x && r > x)
    {
        ll a1 = y - x;
        ll a2;
        if (r <= y)
            a2 = x - l + y - r;
        if (r > y)
            a2 = x - l + r - y;
        ans = min(a1, a2);
    }
    else
    {
        ans = y - x;
    }
    cout << ans br;

    return 0;
}