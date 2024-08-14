// Leetcode : https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
// Way - I (BFS)
class Solution
{
    void bfs(TreeNode *root, vector<vector<int>> &nodes, int level)
    {
        if (!root)
            return;
        if (level >= nodes.size())
            nodes.push_back({});
        nodes[level].push_back(root->val);
        bfs(root->left, nodes, level + 1);
        bfs(root->right, nodes, level + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        bfs(root, ans, 0);
        return ans;
    }
};

// Way - II (Iterative [Queue])
class Solution
{
    void bfs(TreeNode *root, vector<vector<int>> &nodes, int level)
    {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            // Get the size of the current level of tree
            int n = q.size();
            vector<int> currLevel;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                currLevel.push_back(node->val);
            }
            nodes.push_back(currLevel);
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        bfs(root, ans, 0);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (BFS)
class Solution
{
    private void bfs(TreeNode root, List<List<Integer>> nodes, int level)
    {
        if (root == null)
            return;
        if (level >= nodes.size())
            nodes.add(new ArrayList<>());
        nodes.get(level).add(root.val);
        bfs(root.left, nodes, level + 1);
        bfs(root.right, nodes, level + 1);
    }

    public List<List<Integer>> levelOrder(TreeNode root)
    {
        List<List<Integer>> ans = new ArrayList<>();
        bfs(root, ans, 0);
        return ans;
    }
}

// Way - II (Iterative [Queue])
class Solution
{
    private void bfs(TreeNode root, List<List<Integer>> nodes, int level)
    {
        if (root == null)
            return;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty())
        {
            int n = q.size();
            List<Integer> currLevel = new ArrayList<>();
            for (int i = 0; i < n; i++)
            {
                TreeNode node = q.poll();
                if (node.left != null)
                    q.add(node.left);
                if (node.right != null)
                    q.add(node.right);
                currLevel.add(node.val);
            }
            nodes.add(currLevel);
        }
    }

    public List<List<Integer>> levelOrder(TreeNode root)
    {
        List<List<Integer>> ans = new ArrayList<>();
        bfs(root, ans, 0);
        return ans;
    }
}
