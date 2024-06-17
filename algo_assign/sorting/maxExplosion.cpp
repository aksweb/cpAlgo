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
#define br << endl

int main()
{

    int n;
    cin >> n;
    vector<ll> pos(n);
    rep(i, 0, n) cin >> pos[i];
    sort(pos.begin(), pos.end());

    ll ans = 0;

    // trying out for all positions
    rep(i, 1, n)
    {
        ll temp = 1;

        // left
        ll impact = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (abs(pos[j] - pos[j + 1]) <= impact)
            {
                impact++;
                temp++;
            }
            else
                break;
        }
        // right
        impact = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (abs(pos[j] - pos[j - 1]) <= impact)
            {
                impact++;
                temp++;
            }
            else
                break;
        }
        ans = max(ans, temp);
    }
    cout << ans br;

    return 0;
}
