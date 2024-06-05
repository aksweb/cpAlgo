#include <bits/stdc++.h>
using namespace std;

int LIS(const vector<int> &arr)
{
    vector<int> lis;
    for (int x : arr)
    {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    return lis.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    int max_lis = 0;

    // Check the LIS without any reversal
    max_lis = LIS(arr);

    // Check the LIS for each possible subarray reversal
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            // Reverse subarray arr[i..j]
            reverse(arr.begin() + i, arr.begin() + j + 1);

            // Calculate LIS for the modified array
            max_lis = max(max_lis, LIS(arr));

            // Restore the original array
            reverse(arr.begin() + i, arr.begin() + j + 1);
        }
    }

    cout << max_lis << endl;
    return 0;
}
