// TSETEN
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        vector<int> arr(16, 0);
        for (int i = 0; i < 16; i++)
            cin >> arr[i];
        vector<int> arr2 = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        mp[arr[0]] = 0;
        mp[arr[1]] = 1;
        mp[arr[2]] = 1;

        for (int i = 3; i <= 6; i++)
        {
            mp[arr[i]] = 2;
        }
        for (int i = 7; i <= 14; i++)
        {
            mp[arr[i]] = 3;
        }
        mp[arr[15]] = 4;

        for (int x : arr2)
            cout << mp[x] << " ";
        cout << "\n";
    }

    return 0;
}