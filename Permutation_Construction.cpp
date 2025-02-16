// TSETEN
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define INF 1000000000000000000

vector<int> constructPermutation(int N)
{
    vector<int> perm(N);
    for (int i = 0; i < N; ++i)
    {
        perm[i] = i + 1;
    }

    if (N > 3)
    {
        reverse(perm.begin(), perm.end());
    }

    return perm;
}

int main()
{
    int T;
    cin >> T;

    vector<int> results[T];

    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        results[i] = constructPermutation(N);
    }

    for (int i = 0; i < T; ++i)
    {
        for (int j = 0; j < results[i].size(); ++j)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
