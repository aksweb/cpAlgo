#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    unordered_map<long long, long long> mp; // Specify both key and value types for unordered_map

    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        if (!mp.count(b)) // Correct usage of checking key existence
            mp[b] = a;
        else
            mp[b] = min(mp[b], a);
    }
    long long ans = -1;
    for (auto it : mp)
    {
        ans = max(ans, it.second); // Accessing the value of the map
    }
    cout << ans;
    return 0;
}
