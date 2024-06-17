// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define pb push_back
#define br << endl

int main()
{

    int n;
    cin >> n;
    vector<pair<ll, ll>> time(n);
    rep(i, 0, n)
    {
        ll a, c;
        cin >> a >> c;
        time.pb({a, c});
    }
    ll ans = 0;
    ll prevServiceTime = 0;
    sort(time.begin(), time.end());
    for (auto x : time)
    {
        ll arrival = x.first;
        ll serviceTime = x.second;
        if (arrival <= prevServiceTime)
        {
            ans += serviceTime;
            prevServiceTime = ans;
        }
        else
        {
            ll waitingTIme = arrival - prevServiceTime;
            ans += waitingTIme + serviceTime;
            prevServiceTime = ans;
        }
    }
    cout << ans br;
    return 0;
}
