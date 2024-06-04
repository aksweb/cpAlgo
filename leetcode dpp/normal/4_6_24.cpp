class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.length();
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            ump[s[i] - 'a']++;
        }
        int ans = 0;
        int fg = 0;
        for (auto x : ump)
        {
            ans += x.second / 2;
            if (x.second % 2 != 0)
            {
                fg = 1;
            }
        }
        ans *= 2;
        if (fg == 1)
            ans++;
        return ans;
    }
};