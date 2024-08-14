// Leetcode : https://leetcode.com/problems/binary-tree-postorder-traversal/description/

/* Postorder Traversal : left, right, root */
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
// Way - I (DFS)
class Solution
{
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// Way - II (Iterative [2 Stacks])
class Solution
{
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left)
                st1.push(node->left);
            if (node->right)
                st1.push(node->right);
        }
        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// Way - III (Iterative [1 Stack])
class Solution
{
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> st;
        TreeNode *node = root, *temp;
        while (node || !st.empty())
        {
            if (node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                temp = st.top()->right;
                if (!temp)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    node = temp;
            }
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
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
        dfs(root.right, ans);
        ans.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        dfs(root, ans);
        return ans;
    }
}

// Way - II (Iterative [2 Stacks])
class Solution
{
    private void dfs(TreeNode root, List<Integer> ans)
    {
        if (root == null)
            return;
        Stack<TreeNode> st1 = new Stack<>(), st2 = new Stack<>();
        st1.push(root);
        while (!st1.isEmpty())
        {
            TreeNode node = st1.pop();
            st2.push(node);
            if (node.left != null)
                st1.push(node.left);
            if (node.right != null)
                st1.push(node.right);
        }
        while (!st2.isEmpty())
            ans.add(st2.pop().val);
    }

    public List<Integer> postorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        dfs(root, ans);
        return ans;
    }
}

// Way - III (Iterative [1 Stack])
class Solution
{
    private void dfs(TreeNode root, List<Integer> ans)
    {
        if (root == null)
            return;
        Stack<TreeNode> st = new Stack<>();
        TreeNode node = root, temp;
        while (node != null || !st.isEmpty())
        {
            if (node != null)
            {
                st.push(node);
                node = node.left;
            }
            else
            {
                temp = st.peek().right;
                if (temp == null)
                {
                    temp = st.pop();
                    ans.add(temp.val);
                    while (!st.isEmpty() && temp == st.peek().right)
                    {
                        temp = st.pop();
                        ans.add(temp.val);
                    }
                }
                else
                    node = temp;
            }
        }
    }

    public List<Integer> postorderTraversal(TreeNode root)
    {
        List<Integer> ans = new ArrayList<>();
        dfs(root, ans);
        return ans;
    }
}