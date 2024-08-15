// Leetcode : https://leetcode.com/problems/diameter-of-binary-tree/description/

/* Maximum diameter can be the maximum distance between two nodes, calculate the highest sum of left depth and right depth of any node. */
// [C++]-----------------------------------------------------------------------------------------------------------------------
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
    int maxDepth(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;
        int leftDepth = maxDepth(root->left, diameter);
        int rightDepth = maxDepth(root->right, diameter);
        diameter = max(diameter, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    int diameter = 0;
    public int diameterOfBinaryTree(TreeNode root)
    {
        maxDepth(root);
        return diameter;
    }
    private int maxDepth(TreeNode root)
    {
        if (root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        diameter = Math.max(diameter, leftDepth + rightDepth);
        return 1 + Math.max(leftDepth, rightDepth);
    }
}