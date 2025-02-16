#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool canTransform(vector<int> &A, vector<int> &B, int K, int N)
{
    map<int, int> countA, countB;

    // Check every K-length block
    for (int i = 0; i < N; i++)
    {
        countA[A[i]]++;
        countB[B[i]]++;

        // When we exceed K, remove the elements that slide out of the window
        if (i >= K)
        {
            countA[A[i - K]]--;
            countB[B[i - K]]--;
            if (countA[A[i - K]] == 0)
                countA.erase(A[i - K]);
            if (countB[B[i - K]] == 0)
                countB.erase(B[i - K]);
        }

        // After adjusting, compare the frequency maps
        if (countA == countB)
            return true;
    }

    return countA == countB;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        if (canTransform(A, B, K, N))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
