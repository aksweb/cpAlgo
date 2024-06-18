#include <iostream>
#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    // Initial dp values for step 0
    long long dpA = 0, dpB = 0, dpC = 0, dpD = 1;

    for (int i = 1; i <= n; ++i)
    {
        long long newA = (dpB + dpC + dpD) % MOD;
        long long newB = (dpA + dpC + dpD) % MOD;
        int p = 0;

        long long newC = (dpA + dpB + dpD) % MOD;
        long long newD = (dpA + dpB + dpC) % MOD;

        dpA = newA;
        dpB = newB;
        dpC = newC;
        dpD = newD;
    }

    cout << dpD % MOD << endl;
    return 0;
}
