// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int _;
    cin >> _;

    while (_--)
    {
        int n, k;
        cin >> n >> k;

        ll s = (k * (k + 1)) / 2;
        if (s + (k - 1) <= n)
            cout << "YES" br;
        else
            cout << "NO" br;
    }

    return 0;
}
