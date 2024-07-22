
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll ppehla, dusra, tesra;
        cin >> ppehla >> dusra >> tesra;
        ll ans = ppehla;
        for (int i = 0; i <= 5; i++)
        {
            for (int j = i; (i + j) <= 5; j++)
            {
                ans = max((ppehla + i) * (dusra + j) * (tesra + (5 - (j + i))), ans);
            }
        }
        cout << ans br;
    }

    return 0;
}
