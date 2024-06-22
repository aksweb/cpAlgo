#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool helper(vector<int> &position, int m, int mid)
    {
        int n = position.size();
        int curr = position[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (curr + mid <= position[i])
                count++;
            curr = position[i];
        }
        if (count >= m)
            return true;
        return false;
    }
    int pred(vector<int> &position, int m, int mid)
    {
        if (helper(position, m, mid))
            return 0;
        return 1;
    }
    int maxDistance(vector<int> &position, int m)
    {
        if (position.size() == 1)
            return 0;
        int l = 0, h = position.back() - position.front();
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (helper(position, m, mid) == 0)
                l = mid;
            h = mid - 1;
        }
        return l;
    }
};