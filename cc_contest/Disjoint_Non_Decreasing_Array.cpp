
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl

#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll _;
    cin >> _;
    while (_--)
    {
        ll n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];

        ll toAdd = 0;
        bool vis[n] = {false};
        for (ll i = 1; i < n;)
        {
            if (a[i] < a[i - 1])
            {
                toAdd = max(a[i - 1] - a[i], toAdd);
                vis[i] = true;
                i += 2;
            }
            else
                i++;
        }
        for (ll i = 0; i < n; i++)
        {
            if (vis[i])
                a[i] += toAdd;
        }
        bool fg = true;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                fg = false;
                break;
            }
        }
        fg ? cout << "Yes" br : cout << "No" br;

        // bool f0 = true, f1 = true;
        // ll d0 = 0, d1 = 0;
        // ll p0 = 0, p1 = 0;
        // ll cutoff0 = 0, cutoff1 = 0;
        // bool is0adj = false;
        // ll zcmp = a[0];
        // ll zmx = -1;
        // for (ll i = 0; i < n - 2; i += 2)
        // {
        //     zmx = max(a[i], zmx);
        //     if ((a[i + 2] - a[i]) < 0)
        //     {
        //         f0 = false;
        //         d0 = a[i] - a[i + 2];
        //         p0 = i + 2;
        //         cutoff0 = a[i + 2];
        //         zcmp = a[i];
        //         // cout << a[i] << " " << a[i + 2] br;
        //         break;
        //     }
        //     // cout << i << " : " << a[i] << " " << a[i + 2] br;
        // }
        // if (!f0)
        // {
        //     // cout << i << " : " << a[i] << " " << a[i + 2] br;
        //     // cout << a[p0 - 2] << " " << a[p0] << " " br;
        //     for (ll i = p0; i < n - 2; i += 2)
        //     {
        //         if (a[i] < cutoff0 && a[i] < cutoff0 + d0)
        //         {
        //             f0 = false;
        //             break;
        //         }
        //         // cout << i << " : " << a[i] << " " << a[i + 2] br;
        //         f0 = true;
        //     }
        //     is0adj = true;
        // }
        // if (!f0)
        // {
        //     cout << "No" br;
        //     continue;
        // }
        // if (is0adj)
        // {
        //     for (ll i = 1; i < n - 2; i += 2)
        //     {
        //         if (a[i] > a[i + 2] || a[i] < zcmp || a[i + 2] < zcmp)
        //         {
        //             f1 = false;
        //             break;
        //         }

        //         // cout << i << " : " << a[i] << " " << a[i + 2] br;
        //     }
        //     if (!f1)
        //     {
        //         cout << "No" br;
        //         continue;
        //     }
        // }
        // else
        // {

        //     for (ll i = 1; i < n - 2; i += 2)
        //     {
        //         if ((a[i + 2] - a[i]) < 0)
        //         {
        //             f1 = false;
        //             d1 = a[i] - a[i + 2];
        //             p1 = i + 2;
        //             cutoff1 = a[i + 2];
        //             break;
        //         }
        //         // cout << i << " : " << a[i] << " " << a[i + 2] br;
        //     }
        //     if (!f1)
        //     {
        //         for (ll i = p1; i < n - 2; i += 2)
        //         {
        //             if (a[i] < cutoff1 && a[i] < cutoff1 + d1)
        //             {
        //                 f1 = false;
        //                 break;
        //             }
        //             else
        //             {
        //             }
        //             // cout << i << " : " << a[i] << " " << a[i + 2] br;
        //             f1 = true;
        //         }
        //     }
        //     if (!f1)
        //     {
        //         cout << "No" br;
        //         continue;
        //     }
        // }
        // ll for (ll i = 1; i < n - 2; i += 2)
        // {
        //     a[i] = a[i] + zmx;

        //     cout << "Yes" br;
    }
    return 0;
}
