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

// ll fact(ll n)
// {
//     if (n == 1 || n == 0)
//         return 1;
//     ll ans = 1;
//     for (ll i = 2; i <= n; i++)
//         ans *= i;
//     return ans;
// }
// // jo cheating kiya, uski ma r****

// void solve()
// {
//     ll _;
//     cin >> _;

//     while (_--)
//     {
//         ll n;
//         cin >> n;

//         vector<int> a(2 * n + 1, 0), l(n), r(n);
//         // unordered_map<int, int> mp;
//         rep(i, n)
//         {
//             cin >> l[i] >> r[i];
//             if (l[i] == r[i])
//                 a[l[i]]++;
//         }
//         vector<int> pfx(2 * n + 1, 0);
//         pfx[0] = 0;
//         for (int i = 1; i <= 2 * n; i++)
//         {
//             pfx[i] = pfx[i - 1] + (a[i] > 0);
//         }
//         string ans = "";
//         rep(i, n)
//         {
//             if (r[i] - l[i] + 1 > pfx[r[i]] - pfx[l[i] - 1])
//             {
//                 ans += '1';
//             }
//             else if ((r[i] == l[i]) && (a[l[i]] == 1))
//                 ans += '1';
//             else
//                 ans += '0';
//         }
//         cout << ans br;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     solve();

//     return 0;
// }

