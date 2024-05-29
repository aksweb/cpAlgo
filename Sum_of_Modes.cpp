#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

long long sumOfModes(const string &S)
{
    int N = S.length();
    vector<int> prefix_sum(N + 1, 0);
    unordered_map<int, int> balance_map;
    long long totalSum = 0;

    // Precompute the prefix sums
    for (int i = 1; i <= N; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] + (S[i - 1] == '1' ? 1 : -1);
    }

    // Traverse through all prefix sums
    for (int i = 0; i <= N; ++i)
    {
        int balance = prefix_sum[i];

        // Add the current balance's count to the total sum
        totalSum += balance_map[balance];

        // If this balance has been seen before, it means there are substrings with this balance
        balance_map[balance]++;

        // If balance is 0, we have an equal number of '0's and '1's from the start
        if (balance == 0)
        {
            totalSum += 1;
        }
    }

    return totalSum;
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
        string S;
        cin >> S;
        cout << sumOfModes(S) << "\n";
    }

    return 0;
}