class Solution
{
public:
    // iterative approach
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        if (root == nullptr)
            return new TreeNode(val);
        TreeNode *curr = root;
        TreeNode *parent = nullptr;

        while (curr != NULL)
        {
            parent = curr;
            if (val > curr->val)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (val > parent->val)
            parent->right = new TreeNode(val);
        else
            parent->left = new TreeNode(val);
        return root;
    }
};

// recursive approachs
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // recursive
        if (root == nullptr)
            return new TreeNode(val);
        else if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};