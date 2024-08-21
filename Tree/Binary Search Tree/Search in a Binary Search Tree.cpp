// Leetcode : https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
// Way - I (Iterative)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *mover = root;
        while (mover)
        {
            if (mover->val == val)
                return mover;
            if (val <= mover->val)
                mover = mover->left;
            else
                mover = mover->right;
        }
        return nullptr;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
            return root;
        if (val <= root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
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
// Way - I (Iterative)
class Solution
{
    public TreeNode searchBST(TreeNode root, int val)
    {
        TreeNode mover = root;
        while (mover != null)
        {
            if (mover.val == val)
                return mover;
            if (val <= mover.val)
                mover = mover.left;
            else
                mover = mover.right;
        }
        return null;
    }
}

// Way - II (Recursive)
class Solution
{
    public TreeNode searchBST(TreeNode root, int val)
    {
        if (root == null || root.val == val)
            return root;
        if (val <= root.val)
            return searchBST(root.left, val);
        else
            return searchBST(root.right, val);
    }
}