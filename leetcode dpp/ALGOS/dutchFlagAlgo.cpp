// ░░████████╗░██████╗███████╗░████████╗███████╗███╗░░██╗
// ░░╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝████╗░██║
// ░░░░░██║░░░╚█████╗░█████╗░░░░░██║░░░█████╗░░██╔██╗██║
// ░░░░░██║░░░░╚═══██╗██╔══╝░░░░░██║░░░██╔══╝░░██║╚████║
// ░░░░░██║░░░██████╔╝███████╗░░░██║░░░███████╗██║░╚███║
// ░░░░░╚═╝░░░╚═════╝░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        const char red = 0, green = 1, blue = 2;
        int l = 0, m = 0, r = nums.size() - 1; // consider m as the refrence.
        while (m <= r)
        {
            switch (nums[m])
            {
            case red:
                swap(nums[l], nums[m]);
                l++;
                m++;
                break;
            case green:
                m++;
                break;

            case blue:
                swap(nums[m], nums[r]);
                r--;
                break;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution obj;
    obj.sortColors(nums);
    for (auto x : nums)
        cout << x << " ";
    return 0;
}
