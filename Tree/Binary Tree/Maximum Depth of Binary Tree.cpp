// Leetcode : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
// Way - I (DFS [Recursion])
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};

// Way - II (DFS [Iterative])
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});
        int ans = 0;
        while (!st.empty())
        {
            pair<TreeNode *, int> top = st.top();
            st.pop();
            // If any of the child exists, push it into stack otherwise update the answer
            if (top.first->left)
                st.push({top.first->left, top.second + 1});
            if (top.first->right)
                st.push({top.first->right, top.second + 1});
            else
                ans = max(ans, top.second);
        }
        return ans;
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
// Way - I (DFS [Recursion])
class Solution
{
public
    int maxDepth(TreeNode root)
    {
        if (root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        return 1 + Math.max(leftDepth, rightDepth);
    }
}

// Way - II (DFS [Iterative])
class Solution
{
public
    int maxDepth(TreeNode root)
    {
        if (root == null)
            return 0;
        Stack<Pair<TreeNode, Integer>> st = new Stack<>();
        st.push(new Pair<>(root, 1));
        int ans = 0;
        while (!st.isEmpty())
        {
            Pair<TreeNode, Integer> top = st.pop();
            // If any of the child exists, push it into stack otherwise update the answer
            if (top.getKey().left != null)
                st.push(new Pair<>(top.getKey().left, top.getValue() + 1));
            if (top.getKey().right != null)
                st.push(new Pair<>(top.getKey().right, top.getValue() + 1));
            else
                ans = Math.max(ans, top.getValue());
        }
        return ans;
    }
}