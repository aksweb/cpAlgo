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

bool cmp(const pair<ll, ll> a, const pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int pred(ll m, ll h)
{

    if (m > h)
        return 0;
    else
        return 1;
}

// Code Begins Here
void solve()
{
    int _;
    cin >> _;

    while (_--)
    {
        int sz;
        cin >> sz;

        vector<int> arr(sz);
        for (auto &el : arr)
            cin >> el;

        vector<int> sec(sz);
        for (auto &el : sec)
            cin >> el;

        int mxf = -1, smxf = -1;
        int maxIdx = -1, secId = -1;

        for (int i = 0; i < sz; i++)
        {
            if (arr[i] > mxf)
            {
                smxf = mxf;
                secId = maxIdx;
                mxf = arr[i];
                maxIdx = i;
            }
            else if (arr[i] > smxf)
            {
                smxf = arr[i];
                secId = i;
            }
        }

        int currMax = max(arr[maxIdx], sec[maxIdx]);
        int newMax = -1;
        int count = 0;
        rep(i, sz)
        {
            if (i != maxIdx)
            {
                if (max(arr[i], sec[i]) >= currMax)
                {
                    count++;
                    newMax = max(newMax, max(arr[i], sec[i]));
                }
            }
        }
        int secMax = (secId == -1 ? -1 : max(arr[secId], sec[secId]));
        if (newMax > currMax || currMax > secMax)
        {
            cout << "Yes" br;
        }
        else
        {
            cout << "No" br;
        }
        // elsew
        // {
        //     int fg = 0;
        //     rep(i, sz)
        //     {
        //         if (i != maxIdx)
        //         {
        //             if (max(arr[i], sec[i]) == currMax)
        //             {
        //                 fg = 1;
        //                 break;
        //             }
        //         }
        //     }
        //     if (fg == 0)
        //         cout << "Yes" br;
        //     else
        //         cout << "No" br;
        //     // int mxPr = max(arr[maxIdx], sec[maxIdx]);
        //     // int mxSec = (secId == -1) ? -1 : max(arr[secId], sec[secId]);

        //     // int maxRest = -1;
        //     // for (int i = 0; i < sz; i++)
        //     // {
        //     //     if (i != maxIdx)
        //     //         maxRest = max(maxRest, max(arr[i], sec[i]));
        //     // }

        //     // if (maxRest > mxPr || mxPr > mxSec)
        //     // {
        //     //     cout << "Yes" br;
        //     // }
        //     // else
        //     // {
        //     //     cout << "No" br;
        //     // }
        // }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
