#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, m, n) for (ll i = m; i < n; i++)
const ll INF = 1e9;

int solve(const vector<int> &a)
{
    int sum = 0;
    for (size_t i = 1; i < a.size(); ++i)
    {
        sum += abs(a[i] - a[i - 1]);
    }
    return sum;
}

int main()
{
    int _;
    cin >> _;

    while (_--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int initialSum = solve(a);
        int maxSum = initialSum;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp = a;

            if (i > 0)
            {
                temp[i] = 1;
                int temp1 = solve(temp);
                maxSum = max(maxSum, temp1);

                temp[i] = k;
                int temp2 = solve(temp);
                maxSum = max(maxSum, temp2);
            }
            else
            {
                temp[i] = k;
                int t1 = solve(temp);
                maxSum = max(maxSum, t1);
            }
        }

        cout << maxSum << endl;
    }

    return 0;
}
