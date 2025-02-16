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
// #define rloop(i, a, b) for (ll i = a; i > b; i--)
// #define trav(a, b) for (auto a : b)
// #define MOD2 629421302
// #define INF 1000000000000000000

// // Ye kab tk likhoge
// ll gcd(ll a, ll b)
// {
//     return (b == 0) ? a : gcd(b, a % b);
// }
// ll lcm(ll a, ll b)
// {
//     return a * (b / gcd(a, b));
// }

// // jo cheating kiya, uski ma r****

// void solve()
// {
//     ll _;
//     cin >> _;

//     while (_--)
//     {
//         ll k, l1, r1, l2, r2;
//         cin >> k >> l1 >> r1 >> l2 >> r2;
//         ll ans = 0;
//         ll st1 = l2 / k, end1 = r2 / k;
//         st1 = min(r1, st1);
//         end1 = min(end1, r1);
//         cout << st1 << " : " << end1 br;
//         ll range1 = end1 - st1;
//         cout << range1 br;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     solve();

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t; // number of test cases
    while (t--)
    {
        int n;
        cin >> n; // length of array a
        vector<int> a(n), b(n);
        unordered_map<int, int> freq;
        int mode = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            freq[b[i] = a[i]]++;
            if (freq[b[i]] > freq[mode] || (freq[b[i]] == freq[mode] && b[i] < mode))
            {
                mode = b[i];
            }
            b[i] = mode;
        }

        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
