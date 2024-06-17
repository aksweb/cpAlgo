// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int min_stands = n;

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        vector<bool> flavors(m, false);
        int count_stands = 0;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                ++count_stands;
                for (int j = 0; j < m; ++j)
                {
                    if (v[i][j] == 'o')
                    {
                        flavors[j] = true;
                    }
                }
            }
        }

        bool all_covered = true;
        for (int j = 0; j < m; ++j)
        {
            if (!flavors[j])
            {
                all_covered = false;
                break;
            }
        }

        if (all_covered)
        {
            min_stands = min(min_stands, count_stands);
        }
    }

    cout << min_stands << endl;

    return 0;
}
