// TSETEN RGIPT
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define ll long long int
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)
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

    ll x;
    cin >> x;
    x = abs(x);
    ll sum = 0, steps = 0;
    while (sum < x || (sum - x) % 2 != 0)
    {
        steps++;
        sum += steps;
    }
    cout << steps br;

    return 0;
}