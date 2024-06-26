// recursive
class Solution
{
public:
    int sum = 0;
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr || root->val < low || root->val > high)
            return 0;
        if (root->val >= low && root->val <= high)
        {
            sum += root->left->val;
        }
        if (root->left != nullptr)
            rangeSumBST(root->left, low, high);
        if (root->right != nullptr)
            rangeSumBST(root->right, low, high);

        return sum;
    }
};

// iterative approach:
class Solution
{
public:
    int sum = 0;
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();

            if (node)
            {
                if (node->val >= low && node->val <= high)
                {
                    sum += node->val;
                }
                if (node->val > low)
                {
                    stk.push(node->left);
                }
                if (node->val < high)
                {
                    stk.push(node->right);
                }
            }
        }

        return sum;
    }
};