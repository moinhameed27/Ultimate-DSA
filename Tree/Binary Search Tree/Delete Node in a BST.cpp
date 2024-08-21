// Leetcode : https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    int findSuccessor(TreeNode *root)
    {
        while (root->left)
            root = root->left;
        return root->val;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Empty Tree
        if (!root)
            return nullptr;
        // Small Value than root, search on the left side
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        // Large Value than root, search on the right side
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            // Case 1 : No Child (Leaf Node)
            if (!root->left && !root->right)
                return nullptr;
            // Case 2 : One Child
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            // Case 3 : Two Children
            // Find the inorder predecessor or inorder successor of the node, replace it with it's value
            root->val = findSuccessor(root->right);
            // Delete the node using the same function, remember send the child node as the current root node has the same value as the successor
            root->right = deleteNode(root->right, root->val);
        }
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
class Solution
{
    public TreeNode deleteNode(TreeNode root, int key)
    {
        if (root == null)
            return null;
        if (key < root.val)
            root.left = deleteNode(root.left, key);
        else if (key > root.val)
            root.right = deleteNode(root.right, key);
        else
        {
            if (root.left == null)
                return root.right;
            if (root.right == null)
                return root.left;
            root.val = findSuccessor(root.right);
            root.right = deleteNode(root.right, root.val);
        }
        return root;
    }

    private int findSuccessor(TreeNode root)
    {
        while (root.left != null)
            root = root.left;
        return root.val;
    }
}