#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minRemovalsToMatchForm(vector<int> &A, int N, int bits)
{
    int mask = (1 << bits) - 1;
    int removalCount = 0;
    for (int i = 0; i < N; ++i)
    {
        if ((A[i] & mask) != mask)
        {
            removalCount++;
        }
    }
    return removalCount;
}

int solve(vector<int> &A, int N)
{
    int minRemovals = INT_MAX;
    for (int i = 1; i <= 31; ++i)
    {
        int currentRemovals = minRemovalsToMatchForm(A, N, i);
        minRemovals = min(minRemovals, currentRemovals);
    }
    return minRemovals;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        cout << solve(A, N) << '\n';
    }

    return 0;
}
