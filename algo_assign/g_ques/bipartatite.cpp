#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Seed and random number generator
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define mod 1000000007
#define MOD1 998244353
const int N = 1e6 + 5;
const long double epsilon = 1e-9;
const int infm = LLONG_MIN;
#define inf 1e18
#define nline << "\n"
#define pf push_front
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define set_bit(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x) // count number of trailing zero in binary representation of unsigned long long int  //  unsigned long long int num = 16; // Binary: 0000000000000000000000000000000000000000000000000000000000010000

string spi = "3141592653589793238462643383279";
// used Given two circles with radii r1 and r2, compare their areas with high precision.

// Convert the string representation of pi to a high precision number if needed
//  long double pi = stold("3." + spi.substr(1)); stold is used to convert string to long double

#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend()

#define fr0(i, a, b) for (ll i = a; i < b; i++)
#define frn(i, a, b) for (ll i = a; i >= b; i--)
#define read(a, n) for0(i, 0, n) cin >> a[i]

#define printi(a, n) for0(i, 0, n) cout << a[i] << " ";

#define yes cout << "YES" \
                 << "\n";
#define no cout << "NO" \
                << "\n";

#define traverse(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)

#define print(a)     \
    for (auto i : a) \
    cout << i << " "

#define vcin(a)       \
    for (auto &i : a) \
    cin >> i

// direction matrix
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

typedef pair<ll, ll> pii;
typedef vector<ll> vl;
#define vvl vector<vector<ll>>
#define vvp vector<pair<ll, ll>>
#define mt(a, b, c) make_tuple(a, b, c)
#define pqmx priority_queue<ll>
#define pqmn priority_queue<ll, vll, greater<ll>>
#define vs vector<string>
#define ump unordered_map<ll, ll>

typedef set<ll> st;
typedef map<ll, ll> mp;
typedef map<ll, vl> mpv;
typedef map<char, ll> mpc;
#define stc set<char>
#define stk stack<ll>
#define stkc stack<char>
#define mpsl map<string, ll>
#define mpls map<ll, string>
#define in insert
#define prec(x) cout << fixed << setprecision(x)
#define n_digit(n) (int)log10(n) + 1
#define msb(n) (int)(log2(n)) + 1

void dfs(ll src, vl &vis, map<int, vl> &adj, bool color)
{

    if (color)
        vis[src] = 1;
    else
        vis[src] = 0;

    color = 1 - color;

    for (auto child : adj[src])
    {
        if (vis[child] == -1)
            dfs(child, vis, adj, color);
    }
}

void gaurav()
{
    ll n;
    cin >> n;
    map<int, vl> adj;

    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vl vis(n + 1, -1);
    dfs(1, vis, adj, 1);

    ll cnta = 0, cntb = 0;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            cnta++;
        else
            cntb++;
    }

    ll total_edges = cnta * cntb;
    ll extra_edges = total_edges - (n - 1);
    cout << extra_edges << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  //   cin.tie(NULL);
    cout.tie(0); //  cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    gaurav();

    return 0;
}