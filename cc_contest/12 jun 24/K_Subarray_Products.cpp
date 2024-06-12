#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, K, M;
        cin >> N >> K >> M;
        vector<long long> A(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        long long totalSum = 0;

        for (int start = 0; start < N; ++start)
        {
            long long currentProduct = 1;
            for (int end = start; end < min(start + K, N); ++end)
            {
                currentProduct *= A[end];
                currentProduct %= M; // Take modulo M at each step to prevent overflow
                totalSum += currentProduct;
                totalSum %= M; // Take modulo M to keep the sum within bounds
                if (currentProduct == 0)
                    break; // Early exit if product becomes zero
            }
        }

        cout << totalSum << "\n";
    }

    return 0;
}
