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

    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    rep(i, 0, n) cin >> v[i];
    ll curr = 0;
    rep(i, 0, n)
    {
        if (v[i] <= curr)
        {
            cout << curr + a br;
            curr = curr + a;
        }
        else
        {
            cout << v[i] + a br;
            curr = v[i] + a;
        }
    }

    return 0;
}
