// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int _;
    cin >> _;

    while (_--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        int ans = 0;

        for (int i = 0; i <= n; ++i)
        {
            int rem = n - i;
            if (rem % 2 == 0)
            {
                int j = rem / 2;
                int ern = (i * x) + (j * y);
                ans = max(ans, ern);
            }
        }

        cout << ans << endl;
    }

    return 0;
}