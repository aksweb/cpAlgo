
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

    string s;
    cin >> s;
    ll len = s.length();

    ll n;
    cin >> n;
    ll a[n];
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }

    ll da[len + 1] = {0};

    rep(i, n)
    {
        da[a[i]]++;
        da[len - a[i]]--;
    }

    for (ll i = 1; i < len; i++)
    {
        da[i] += da[i - 1];
    }
    // rep(i, len) cout << da[i] << " ";
    for (ll i = 0; i < len / 2; i++)
    {
        if (da[i] % 2 == 1)
        {
            swap(s[i], s[len - 1 - i]);
        }
    }

    cout << s br;

    return 0;
}
