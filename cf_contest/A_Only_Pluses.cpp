#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        long long int ans = 0;
        for (int i = 0; i <= 5; i++)
        {
            for (int j = 0; (i + j) <= 5; j++)
            {
                ans = max((a + i) * (b + j) * (c + (5 - (i + j))), ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
