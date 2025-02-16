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
#define rloop(i, a, b) for (ll i = a; i > b; i--)
#define trav(a, b) for (auto a : b)
#define MOD2 629421302
#define INF 1000000000000000000

// Ye kab tk likhoge
ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}

// jo cheating kiya, uski ___

void solve()
{
    int _;
    cin >> _;

    while (_--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<ll, ll>> b;
        rep(i, n)
        {
            if (a[i] >= 0)
                b.push_back({(ll)ceil((a[i] * 1.0) / k), (ll)floor((a[i] * 1.0) / k)});
            else{
                
            }
            // if (a[i] >= 0)
            // else
            //     b.push_back({(ll)floor((a[i] * 1.0) / k), (ll)ceil((a[i] * 1.0) / k)});
        }

        ll fir = 0, sec = 0;
        rep(i, n)
        {
            fir += b[i].first;
            if (b[i].first != b[i].second)
                sec++;
        }
        if (fir == 0)
        {
            cout << "YES" br;
        }
        else
        {
            if (fir >= 0 && sec <= 0)
            {
                cout << "YES" br;
            }
            else
            {
                cout << "NO" br;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}