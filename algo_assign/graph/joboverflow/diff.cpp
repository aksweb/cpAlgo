#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

void rec(vector<vector<int>> &mat, int i, int j, int n, int m, int &cnt)
{
    if (i < 0 || j < 0 || i >= n || j >= m || !mat[i][j])
        return;
    cnt++;
    mat[i][j] = 0;
    rec(mat, i + 1, j, n, m, cnt);
    rec(mat, i, j + 1, n, m, cnt);
    rec(mat, i - 1, j, n, m, cnt);
    rec(mat, i, j - 1, n, m, cnt);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j])
            {
                int cnt = 0;
                rec(mat, i, j, n, m, cnt);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}   