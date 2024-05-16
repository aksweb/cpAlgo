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

// https://leetcode.com/problems/evaluate-boolean-binary-tree/?envType=daily-question&envId=2024-05-16
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val && 1;
        }
        bool v1 = evaluateTree(root->left);
        bool v2 = evaluateTree(root->right);

        if (root->val == 2)
            return v1 || v2;
        else
            return v1 && v2;
    }
};