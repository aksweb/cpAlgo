// https : // leetcode.com/problems/find-common-characters/
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int minCount = INT_MAX;
            for (string wrd : words)
            {
                int count = 0;
                for (char ch2 : wrd)
                {
                    if (ch2 == ch)
                        count++;
                }
                minCount = min(minCount, count);
            }
            if (minCount != 0)
            {
                for (int i = 0; i < minCount; i++)
                {
                    string s(1, ch); // corrected line
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};