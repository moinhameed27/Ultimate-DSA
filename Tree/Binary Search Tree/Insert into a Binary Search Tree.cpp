// Leetcode : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);
        // Empty Tree
        if (root == nullptr)  
            return newNode;
        TreeNode *mover = root, *prev = nullptr;    // Prev pointer to keep track of parent node
        while (mover)
        {
            prev = mover;
            if (val <= mover->val)
                mover = mover->left;
            else
                mover = mover->right;
        }
        // If insertion is to be done in the left subtree
        if (val <= prev->val)
            prev->left = newNode;
        // If insertion is to be done in the right subtree
        else
            prev->right = newNode;
        return root;
    }
};

/* When root reaches null, return newNode with value val, otherwise assign left to the left recursion call and same for right */
// Way - II (Recursive)
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        if (val <= root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
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
    public TreeNode insertIntoBST(TreeNode root, int val)
    {
        TreeNode newNode = new TreeNode(val);
        if (root == null)
            return newNode;
        TreeNode mover = root, prev = null;
        while (mover != null)
        {
            prev = mover;
            if (val <= mover.val)
                mover = mover.left;
            else
                mover = mover.right;
        }
        if (val <= prev.val)
            prev.left = newNode;
        else
            prev.right = newNode;
        return root;
    }
}

// Way - II (Recursive)
class Solution
{
    public TreeNode insertIntoBST(TreeNode root, int val)
    {
        if (root == null)
            return new TreeNode(val);
        if (val <= root.val)
            root.left = insertIntoBST(root.left, val);
        else
            root.right = insertIntoBST(root.right, val);
        return root;
    }
}