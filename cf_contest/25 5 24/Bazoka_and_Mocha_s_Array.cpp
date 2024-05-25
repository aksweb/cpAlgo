#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

// Helper function to check if the array is sorted in non-decreasing order
bool is_sorted(const vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Function to determine if the array can be sorted by prefix-suffix swapping
bool can_be_sorted_by_swapping_prefix_suffix(const vector<int> &arr)
{
    int n = arr.size();
    // Check all cyclic permutations
    for (int i = 0; i < n; ++i)
    {
        // Create a cyclic permutation
        vector<int> rotated(arr.begin() + i, arr.end());
        rotated.insert(rotated.end(), arr.begin(), arr.begin() + i);

        if (is_sorted(rotated))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        if (can_be_sorted_by_swapping_prefix_suffix(a))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
