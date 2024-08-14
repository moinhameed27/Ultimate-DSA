// Leetcode : https://leetcode.com/problems/binary-tree-preorder-traversal/description/

/* Preorder Traversal : Root, left, right */
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
        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
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
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
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
        ans.add(root.val);
        dfs(root.left, ans);
        dfs(root.right, ans);
    }

    public List<Integer> preorderTraversal(TreeNode root)
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
        st.push(root);
        while (!st.isEmpty())
        {
            TreeNode node = st.pop();
            ans.add(node.val);
            if (node.right != null)
                st.push(node.right);
            if (node.left != null)
                st.push(node.left);
        }
    }

    public List<Integer> preorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        dfs(root, ans);
        return ans;
    }
}