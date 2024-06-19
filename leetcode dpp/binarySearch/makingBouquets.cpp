// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/?envType=daily-question&envId=2024-06-19
class Solution
{
public:
    bool helper(vector<int> &bloomDay, int m, int k, int mid)
    {
        int cnt = 0;
        for (int i = 0; i < bloomDay.size() - k + 1; i++)
        {
            if (bloomDay[i] > mid)
                continue;
            int tmp = 0;
            for (int j = i; j < i + k; j++)
            {
                if (bloomDay[j] <= mid)
                    tmp++;
                else
                    break;
            }
            if (tmp == k)
            {
                cnt++;
                i += k - 1;
            }
        }
        if (cnt >= m)
            return true;
        return false;
    }
    int pred(vector<int> &bloomDay, int m, int k, int mid)
    {
        if (helper(bloomDay, m, k, mid))
            return 0;
        return 1;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (long(m) * k > long(bloomDay.size()))
            return -1;
        int l = 0, h = *std::max_element(bloomDay.begin(), bloomDay.end());
        while (l + 1 <= h)
        {
            int mid = l + (h - l) / 2;
            if (pred(bloomDay, m, k, mid) == 0)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};