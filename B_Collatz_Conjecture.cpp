#include <iostream>
#include <vector>
using namespace std;

// Function to perform the operations as described in the problem
long long collatz(long long x, long long y, long long k)
{
    for (long long i = 0; i < k; ++i)
    {
        x += 1;
        while (x % y == 0)
        {
            x /= y;
        }
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> results;

    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        results.push_back(collatz(x, y, k));
    }

    for (long long result : results)
    {
        cout << result << endl;
    }

    return 0;
}
