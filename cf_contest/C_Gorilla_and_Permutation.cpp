
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> ans;
        if (k <= n)
        {
            int st = k;
            while (st <= n)
            {
                ans.push_back(st);
                st++;
            }
            for (int i = 1; i < k; i++)
            {
                ans.push_back(i);
            }
        }
        else
        {
            for (int i = n; i > 0; i--)
                ans.push_back(i);
        }
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
