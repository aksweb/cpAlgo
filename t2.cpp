// TSETEN
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define INF 1000000000000000000

vector<int> cP(int n)
{
    vector<int> perm(n);
    int idx = 0;
    
    for (int i = 0; i < n; i += 2)
    {
        perm[i] = ++idx;
    }

    for (int i = 1; i < n; i += 2)
    {
        perm[i] = ++idx;
    }

    return perm;
}

int main()
{
    int _;
    cin >> _;

    vector<vector<int>> res(_);

    for (int i = 0; i < _; ++i)
    {
        int n;
        cin >> n;
        res[i] = cP(n);
    }

    for (int i = 0; i < _; ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
