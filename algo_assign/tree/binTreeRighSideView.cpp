/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *node, unordered_map<int, vector<int>> &ump, int level)
    {
        if (!node)
            return;
        ump[level].push_back(node->val);
        solve(node->left, ump, level + 1);
        solve(node->right, ump, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        int level = 0;
        unordered_map<int, vector<int>> ump;
        solve(root, ump, level);
        vector<int> result;

        for (int i = 0; i < ump.size(); i++)
        {
            if (!ump[i].empty())
            {
                result.push_back(ump[i].back());
            }
        }
        // printing in LIFO order
        //  for (const auto& x : ump) {
        //  if (!x.second.empty()) {  // Check if the vector is not empty
        //      cout<<x.second.back()<<" ";
        //      result.push_back(x.second.back());
        //  }
        //  }
        return result;
    }
};