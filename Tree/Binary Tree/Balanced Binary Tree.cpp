// Leetcode : https://leetcode.com/problems/balanced-binary-tree/description/

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftDepth = maxDepth(root->left);
        if (leftDepth == -1)
            return -1;
        int rightDepth = maxDepth(root->right);
        if (rightDepth == -1)
            return -1;
        if (abs(leftDepth - rightDepth) > 1)
            return -1;
        return 1 + max(leftDepth, rightDepth);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return maxDepth(root) != -1;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution
{
    private int maxDepth(TreeNode root)
    {
        if (root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        if (leftDepth == -1)
            return -1;
        int rightDepth = maxDepth(root.right);
        if (rightDepth == -1)
            return -1;
        if (Math.abs(leftDepth - rightDepth) > 1)
            return -1;
        return 1 + Math.max(leftDepth, rightDepth);
    }
    public boolean isBalanced(TreeNode root)
    {
        return maxDepth(root) != -1;
    }
}