// Leetcode : https://leetcode.com/problems/symmetric-tree/description/

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
// Way - I (Iterative [BFS])
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, root});
        while (!q.empty())
        {
            auto [Node1, Node2] = q.front();
            q.pop();
            if (!Node1 && !Node2)
                continue;
            if (!Node1 || !Node2 || Node1->val != Node2->val)
                return false;
            q.push({Node1->left, Node2->right});
            q.push({Node1->right, Node2->left});
        }
        return true;
    }
};

// Way - II (Recursive [DFS])
class Solution
{
    bool isMirror(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 && !node2)
            return true;
        if (!node1 || !node2)
            return false;
        return node1->val == node2->val && isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root->left, root->right);
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
// Way - I (Iterative [BFS])
class Solution
{
    public boolean isSymmetric(TreeNode root)
    {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(root);
        while (!q.isEmpty())
        {
            TreeNode node1 = q.poll();
            TreeNode node2 = q.poll();
            if (node1 == null && node2 == null)
                continue;
            if (node1 == null || node2 == null || node1.val != node2.val)
                return false;
            q.add(node1.left);
            q.add(node2.right);
            q.add(node1.right);
            q.add(node2.left);
        }
        return true;
    }
}

// Way - II (Recursive [DFS])
class Solution
{
    public boolean isSymmetric(TreeNode root)
    {
        return isMirror(root.left, root.right);
    }

    public boolean isMirror(TreeNode node1, TreeNode node2)
    {
        if (node1 == null && node2 == null)
            return true;
        if (node1 == null || node2 == null)
            return false;
        return node1.val == node2.val && isMirror(node1.left, node2.right) && isMirror(node1.right, node2.left);
    }
}