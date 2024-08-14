// Leetcode : https://leetcode.com/problems/binary-tree-inorder-traversal/description/

/* Inorder Traversal : left, root, right */
// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (DFS)
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
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// Way - II (Iterative [Stack])
class Solution
{
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (node || !st.empty())
        {
            while (node)
            {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }   
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (DFS)
class Solution
{
    private void dfs(TreeNode root, List<Integer> ans)
    {
        if (root == null)
            return;
        dfs(root.left, ans);
        ans.add(root.val);
        dfs(root.right, ans);
    }
    public List<Integer> inorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        dfs(root, ans);
        return ans;
    }
}

// Way - II (Iterative [Stack])
class Solution
{
    private void dfs(TreeNode root, List<Integer> ans)
    {
        if (root == null)
            return;
        Stack<TreeNode> st = new Stack<>();
        TreeNode node = root;
        while (node != null || !st.isEmpty())
        {
            // First go to the left most node
            while (node != null)
            {
                st.push(node);
                node = node.left;
            }
            node = st.pop();
            ans.add(node.val);
            node = node.right;
        }
    }
    public List<Integer> inorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        dfs(root, ans);
        return ans;
    }
}