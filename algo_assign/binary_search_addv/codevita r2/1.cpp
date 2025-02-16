// TSETEN RGIPT
// TODAY
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

// jo cheating kiya, uski ma r****

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, n)
    {
        cin >> a[i].first >> a[i].second;
    }
    map<ll, ll> fmp;
    for (ll i = 0; i < n; i++)
    {
        if (fmp.find(a[i].first) != fmp.end())
        {
            fmp[a[i].first] = min(fmp[a[i].first], a[i].second);
        }
        else
        {
            fmp[a[i].first] = a[i].second;
        }
    }
    vector<pair<ll, ll>> fv;
    for (auto x : fmp)
    {
        fv.push_back({x.first, x.second});
    }
    // for (auto x : fmp)
    //     cout << x.first << " " << x.second br;
    // sort(fv.begin(), fv.end());
    ll ln = fv.size();
    ll mn = INT_MAX;
    vector<pair<ll, ll>> c;
    ll idx = 0;
    bool fg = false;
    ll x = INT_MIN;
    rep(i, ln)
    {
        if (fv[i].second < mn && fv[i].first > x)
        {
            c.push_back({fv[i].first, fv[i].second});
            mn = min(mn, fv[i].second);
            if (i == n - 1)
                fg = true;
            idx = i;
            x = fv[i].first;
        }
    }

    bool fg2 = true;
    mn = fv[ln - 1].second;
    vector<pair<ll, ll>> c2;
    ll idx2 = idx, idxfg = ln - 1;
    for (ll i = ln - 1; i > idx; i--)
    {
        if (fv[i].second < mn && ((fg2 && (fv[i].first > x)) || fv[i].first < x))
        {
            c2.push_back({fv[i].first, fv[i].second});
            mn = min(fv[i].second, mn);
            x = fv[i].first;
            fg2 = false;
            idxfg = i;
        }
        if (fv[i].second <= mn && ((fg2 && (fv[i].first > x)) || fv[i].first < x))
        {
            idx2 = i;
        }
    }
    cout << fv[idx].second << " " << fv[idxfg].second br;
    if ((fv[idx2].second == fv[idx2].second) && (idx2 > idxfg))
    {
        c.push_back({fv[idx2].first, fv[idx2].second});
    }
    reverse(c2.begin(), c2.end());
    ll sz2 = c2.size();
    rep(i, sz2)
    {
        c.push_back(c2[i]);
    }

    // rep(i, c2.size()) cout << c2[i].first << " " << c2[i].second br;
    double ans = 0;
    ll sz = c.size() - 1;
    for (ll i = 0; i < sz; i++)
    {
        ll x = c[i].first;
        ll y = c[i].second;
        ll z = c[i + 1].first;
        ll w = c[i + 1].second;

        double val = sqrt(pow((double)(z - x), 2) + pow((double)(w - y), 2));
        ans += val;
    }
    cout << (ll)ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
