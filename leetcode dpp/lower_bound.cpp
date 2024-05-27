class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= 1000; i++)
        {
            int count = nums.end() - lower_bound(nums.begin(), nums.end(), i);
            if (count == i)
                return i;
        }
        return -1;
    }
};