#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll check(vector<ll> &p, ll c, ll busLeft, ll t)
{
    ll n = p.size();
    // can we transport all passengers by wait max= t;
    ll currCap = 1;
    ll currTime = p[0];
    ll passGone = 1;
    for (int i = 1; i < n; i++)
    {
        if (currCap < c && busLeft > 0)
        {
            // check onboard possible or not
            if (p[i] - currTime <= t)
            {
                currCap++;
                passGone++;
            }
        }
        // can we change the bus
        else if (busLeft > 0)
        {
            currCap = 1;
            currTime = p[i];
            passGone++;
            busLeft--;
        }
    }
    // cout << passGone << " ";
    return (passGone == n ? 1 : 0);
}
int main()
{

    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    ll l = 0, h = p[n - 1];
    ll ans = 0;
    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        if (check(p, c, m, mid) == 1)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}

// // TSETEN RGIPT
// // ΣDAY
// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;
// #define ll long long int
// #define br << endl
// #define rep(i, n) for (ll i = 0; i < n; i++)
// #define repi(i, n) for (ll i = 1; i <= n; i++)
// #define repii(i, n) for (ll i = 1; i < n; i++)
// #define gcd __gcd
// const ll MOD = 1e9 + 7;

// // question rd k l
// // constraits
// // consider tc
// // isse achha approach nhi melega bhai.

// // Ye kab tk likhoge
// ll gcd(ll a, ll b)
// {
//     return (b == 0) ? a : gcd(b, a % b);
// }
// ll lcm(ll a, ll b)
// {
//     return a * (b / gcd(a, b));
// }

// bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
//     else
//         return a.first > b.first;
// }

// // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// // Code Begins Here
// // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// int pred(ll m, ll a[], int n, int b, int c)
// {
//     int nop = 0;
//     int i = 0;
//     while (b--)
//     {
//         ll st = a[i];
//         ll mx_wt = a[i] + m;
//         int cc = c;
//         ll ii = i;
//         while (i < n && a[i] <= mx_wt && cc > 0)
//         {
//             nop++;
//             i++;
//             cc--;
//         }
//     }
//     if (nop == n)
//         return 1;
//     else
//         return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, b, c;
//     cin >> n >> b >> c;
//     ll a[n];
//     ll mx = -1;
//     ll mn = 1e9 + 7;

//     if (n == b)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         mx = max(mx, a[i]);
//         mn = min(a[i], mn);
//     }
//     sort(a, a + n);
//     ll l = 0, r = mx - mn;
//     while (l + 1 < r)
//     {
//         ll m = (l + r) / 2;
//         if (pred(m, a, n, b, c) == 0)
//         {
//             l = m;
//         }
//         else
//         {
//             r = m;
//         }
//     }
//     cout << r;
//     return 0;
// }