// TSETEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

int main()
{
    ll n, cap;
    cin >> n >> cap;

    vector<pair<double, ll>> temp(n);
    rep(i, 0, n)
    {
        double v, w;
        cin >> v >> w;

        temp[i] = {v / w, w};
    }

    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());

    double ans = 0;
    rep(i, 0, n)
    {
        if (cap == 0)
        {
            break;
        }
        double ppu = temp[i].first;
        ll cwt = temp[i].second;

        if (cap - cwt >= 0)
        {
            ans += cwt * ppu;
            cap -= cwt;
        }
        else
        {
            ans += cap * ppu;
            cap = 0;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}