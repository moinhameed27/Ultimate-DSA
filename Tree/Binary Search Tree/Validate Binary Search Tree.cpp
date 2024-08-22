// Leetcode : https://leetcode.com/problems/validate-binary-search-tree/description/

/* Maintain a range, if an element is out of the range, return false */
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
    bool solve(TreeNode *root, long left, long right)
    {
        if (root == nullptr)
            return true;
        if (root->val <= left || root->val >= right)
            return false;
        return solve(root->left, left, root->val) && solve(root->right, root->val, right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return solve(root, LONG_MIN, LONG_MAX);
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
    private boolean solve(TreeNode root, long left, long right)
    {
        if (root == null)
            return true;
        if (root.val <= left || root.val >= right)
            return false;
        return solve(root.left, left, root.val) && solve(root.right, root.val, right);
    }
    public boolean isValidBST(TreeNode root)
    {
        return solve(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}