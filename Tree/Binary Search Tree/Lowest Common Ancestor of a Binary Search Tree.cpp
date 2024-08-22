// Leetcode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/*
1. If both p and q are greater than the root, then LCA lies in the right subtree.
2. If both p and q are lesser than the root, then LCA lies in the left subtree.
3. In any of the other cases, the root is the LCA.
*/
// [C++]-----------------------------------------------------------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Way - I (Iterative)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        TreeNode *mover = root;
        while (mover)
        {
            int curr = mover->val;
            if (curr < p->val && curr < q->val)
                mover = mover->right;
            else if (curr > p->val && curr > q->val)
                mover = mover->left;
            else
                return mover;
        }
        return nullptr;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        int curr = root->val;
        if (curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// Way - I (Iterative)
class Solution
{
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        if (root == null)
            return root;
        TreeNode mover = root;
        while (mover != null)
        {
            int curr = mover.val;
            if (curr < p.val && curr < q.val)
                mover = mover.right;
            else if (curr > p.val && curr > q.val)
                mover = mover.left;
            else
                return mover;
        }
        return null;
    }
}

// Way - II (Recursive)
class Solution
{
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        if (root == null)
            return root;
        int curr = root.val;
        if (curr < p.val && curr < q.val)
            return lowestCommonAncestor(root.right, p, q);
        if (curr > p.val && curr > q.val)
            return lowestCommonAncestor(root.left, p, q);
        return root;
    }
}