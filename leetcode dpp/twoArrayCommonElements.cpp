
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int x : nums1)
            m1[x]++;
        for (int x : nums2)
            m2[x]++;
        vector<int> ans;
        for (auto &x : m1)
        {
            if (m2.count(x) && m2[x] > 0)
            {
                for (int i = 0; i < min(m1[x], m2[x]); i++)
                    ans.push_back(x);
            }
        }
        return ans;
    }
};