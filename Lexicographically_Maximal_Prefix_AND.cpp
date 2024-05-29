#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
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

        // Sort A in descending order
        sort(A.begin(), A.end(), greater<int>());

        // Construct B based on the sorted A
        vector<int> B(N);
        B[0] = A[0];
        for (int i = 1; i < N; ++i)
        {
            B[i] = B[i - 1] & A[i];
        }

        // Print the resulting array B
        for (int i = 0; i < N; ++i)
        {
            cout << B[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}