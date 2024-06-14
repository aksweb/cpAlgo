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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end());

    int max_teams = 0;

    for (int s = 2; s <= 2 * n; s++)
    {
        int temp_teams = 0;
        vector<bool> used(n, false); 

        for (int i = 0; i < n; i++)
        {
            if (used[i])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (!used[j] && a[i] + a[j] == s)
                {
                    used[i] = used[j] = true;
                    temp_teams++;
                    break;
                }
            }
        }
        max_teams = max(max_teams, temp_teams);
    }

    cout << max_teams br;
    return 0;
}
