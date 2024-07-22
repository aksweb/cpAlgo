
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        int ind = 0;
        vector<long long int> v(m);
        long long int mx = -1;
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
            if (v[i] >= mx)
            {
                ind = i;
                mx = v[i];
            }
        }
        long long int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (i != ind)
            {
                if (v[i] == 1)
                    ans++;
                else
                {
                    ans += v[i] + v[i] - 1;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
