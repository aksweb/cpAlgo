
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define br << endl
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];
        priority_queue<ll> pq;
        vector<bool> vis(n, false);
        for (ll i = 0; i < n; i++)
        {

            if (a[i] < 0)
            {
                ll j = i;
                ll tmp = 0;
                while (a[i] < 0)
                {
                    tmp += a[i];
                    vis[i] = true;
                    i++;
                }
                if (i - j == 1 && (j - 1 >= 0) && (!vis[j - 1]))
                {
                    tmp += a[j - 1];
                    vis[j - 1] = true;
                }
                else if (i - j == 1 && i < n && !vis[i])
                {
                    tmp += a[i];
                    // cout << "el if: " << a[j - 1] br;
                    vis[i] = true;
                }
                // cout << "push: " << tmp br;
                if (fx == 1)
                    pq.push(-tmp);
            }
        }
        ll ans = 0;

        ll turn = 1;
        while (!pq.empty())
        {
            ll val = -pq.top();
            pq.pop();
            if (turn % 2 == 1)
            {
                ans += abs(val);
                turn++;
            }
            else
            {
                ans += val;
                turn++;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                // cout << " add: " << a[i] << " ";
                ans += a[i];
            }
        }
        cout << ans br;
    }
    return 0;
}
