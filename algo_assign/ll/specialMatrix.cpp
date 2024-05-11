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

// Code Begins Here
bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

// print the 1st index
int pred(ll m, ll b)
{
    if (m < b)
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    ll a[n][m];
    rep(i, n)
    {
        rep(j, m) cin >> a[i][j];
    }
    vector<ll> pa;
    rep(i,n){
        ll temp=0;
        rep(j,n){
            temp+=a[j][i];
        }
        pa.push_back(temp);
    }
    pa.resize(n);
    sort()
    ll ans=LLONG_MAX;
    rep(i, n)
    {
        ll temp = pa[i];
        rep(j, n)
        {
            temp+=pa[i]-
            temp += a[j][i];
        }
        pa.push_back(temp);
    }

    while (q--)
    {
        ll b;
        cin >> b;
        rep(i, n)
        {
            if (b <= a[i][m - 1])
            {
                int l = -1, r = m;
                while (l + 1 < r)
                {
                    int m = (l + r) / 2;
                    if (pred(a[i][m], b) == 0)
                        l = m;
                    else
                        r = m;
                }
                cout << i << " " << r br;
                break;
            }
        }
    }

    return 0;
}
