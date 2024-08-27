// Leetcode : https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (!front)
                flag = true;
            else
            {
                if (flag)
                    return false;

                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        return isCompleteTree(root, 0, countNodes(root));
    }

    bool isCompleteTree(TreeNode *root, int index, int nodes)
    {
        if (!root)
            return true;
        if (index >= nodes)
            return false;
        return isCompleteTree(root->left, 2 * index + 1, nodes) && isCompleteTree(root->right, 2 * index + 2, nodes);
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
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
    public boolean isCompleteTree(TreeNode root)
    {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean flag = false;
        while (!q.isEmpty())
        {
            TreeNode front = q.poll();
            if (front == null)
            {
                flag = true;
            }
            else
            {
                if (flag)
                    return false;
                q.add(front.left);
                q.add(front.right);
            }
        }
        return true;
    }
}

// Way - II (Recursive)
class Solution
{
    public boolean isCompleteTree(TreeNode root)
    {
        return isCompleteTree(root, 0, countNodes(root));
    }

    public boolean isCompleteTree(TreeNode root, int index, int nodes)
    {
        if (root == null)
            return true;
        if (index >= nodes)
            return false;
        return isCompleteTree(root.left, 2 * index + 1, nodes) && isCompleteTree(root.right, 2 * index + 2, nodes);
    }

    public int countNodes(TreeNode root)
    {
        if (root == null)
            return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}