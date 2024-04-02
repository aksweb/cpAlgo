#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define pb push_back
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define vin(v)        \
    for (auto &x : v) \
        cin >> x;
#define cno                   \
    {                         \
        cout << "NO" << endl; \
        return;               \
    }
#define cyes                   \
    {                          \
        cout << "YES" << endl; \
        return;                \
    }

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;
typedef priority_queue<int> prq;

int fun(vi &a, vi &b, int m) // any other required values for the fun
{
    // return 0 if it is less than sum thing we are searching for or return 1
    int sum = 0;
    if (m == b.size() || m == -1)
        return INT32_MAX;
    for (int i = 0; i < b.size(); i++)
    {
        int y = i - m;
        if (y < 0)
        {
            y *= -1;
            y = b[m] - b[i] - y;
        }
        else
        {
            y = b[i] - b[m] - y;
        }
        sum += y;
    }
    // cout<<sum<<"oginrg\n";
    return sum;
}

void code()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int x = c;
    vi a(n);
    vi b;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i];
        if (a[i] == x)
            b.pb(i);
    }
    int l = -1;
    int r = b.size();
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    while (r - l >= 3)
    {
        int f1 = fun(a, b, m1); // evaluates the function at m1
        int f2 = fun(a, b, m2); // evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
        {
            r = m2;
        }
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        // cout<<f1<<" "<<f2<<"rrr\n";
        // cout<<m1<<" "<<m2<<"\n";
        // cout<<l<<" "<<r<<"\n";
    }
    cout << min(fun(a, b, l), min(fun(a, b, r), fun(a, b, (r + l) / 2)));
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        code();
    return 0;
}