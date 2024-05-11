// TESTEN RGIPT
// ΣDAY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    // Unlike arrays, vectors in C++ do not necessarily store their elements in contiguous memory locations.While vectors do use contiguous memory under the hood, the vector class abstracts this detail away from the user, providing a dynamic array - like interface
    // int a[1001][1001] = {0};
    vector<vector<int>>
        a(1001, vector<int>(1001, 0));

    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                a[i][j]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (a[i][j] == k)
                ans++;
        }
    }

    cout << ans br;

    return 0;
}
