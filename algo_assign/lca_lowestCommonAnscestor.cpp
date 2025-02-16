#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int k)
    {
        val = k;
        left = nullptr;
        right = nullptr;
    }
};

bool isPath(Node *root, int k, vector<int> &path)
{
    if (root == nullptr)
        return false;
    path.push_back(root->val);
    if (root->val == k)
        return true;
    if ((root->left && isPath(root->left, k, path)) || (root->right && isPath(root->right, k, path)))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int solve(Node *root, int a, int b)
{
    vector<int> p1, p2;
    if (isPath(root, a, p1) && isPath(root, b, p2))
    {
        for (int i = 0; i < p1.size() && i < p2.size(); i++)
        {
            
            if (p1[i] == p2[i])
                return p1[i];
        }
    }
    return -1;
}
int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);

    cout << solve(tree, 4, 7);

    return 0;
}