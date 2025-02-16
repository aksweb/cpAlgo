class Solution
{
private:
    struct Trie
    {
        vector<vector<int>> t;
        vector<int> hotNode;
        int curr = 0;
        Trie() : t(32, vector<int>(2, -1)), hotNode(32, 0), curr(0) {}
    };
    void insert(Trie &t, const int &no)
    {
        int n = no;
        int curr = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (!t.t[curr][bit])
            {
                t.t[curr][bit] = ++t.curr;
            }
            curr = t.t[curr][bit];
        }
    }
    int check(Trie &t, int n)
    {
        int res = 0;
        int curr = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (((n >> i) & 1 )== 0)
            {
                if (t.t[curr][1])
                {
                    res += (1 << i);
                    curr = t.t[curr][1];
                }
                else
                {
                    curr = t.t[curr][0];
                }
            }
            else
            {
                if (t.t[curr][0])
                {
                    curr = t.t[curr][0];
                }
                else
                {
                    res += (1 << i);
                    curr = t.t[curr][1];
                }
            }
        }
        return res;
    }

public:
    // with trie
    int maximumStrongPairXor(vector<int> &nums)
    {
        Trie t;
        for (int i = 0; i < nums.size(); i++)
        {
            insert(t, nums[i]);
        }
        int ans=0;
        // find maximum XOR by comparing each bit of all the numbers. if opposite bit is present, then add turn on that bit in the res. Then finally return res and do XOR and choose maxinmum value. This will be the maximum XOR of any 2 elements form the array.
        for (int i = 0; i < nums.size(); i++)
        {
            int no = check(t, nums[i]);
            ans = max(ans, no ^ nums[i]);
        }
        return ans;
    }
};

// without trie
//  int maximumStrongPairXor(vector<int>& nums) {
//      int ans=0;
//      for(int i=0; i<nums.size ();i++){
//          for(int j=0; j<nums.size(); j++){
//              if(i!=j){
//                  if(abs(nums[i]-nums[j])<= min(nums[i], nums[j])){
//                      ans= max(ans, nums[i]^nums[j]);
//                  }
//              }
//          }
//      }
//      return ans;
//  }