// Leetcode : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
// Way - I (Brute Force [Inorder Traversal (Vector)]) : O(n) time and O(n) space
class Solution
{
    void solve(TreeNode *root, int k, vector<int> &v)
    {
        if (!root)
            return;
        solve(root->left, k, v);
        v.push_back(root->val);
        solve(root->right, k, v);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        solve(root, k, inorder);
        return inorder[k - 1];
    }
};

// Way - II (Count) : O(n) time and O(1) space
class Solution
{
    void solve(TreeNode *root, int k, int &count, int &ans)
    {
        if (!root)
            return;
        solve(root->left, k, count, ans);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        solve(root->right, k, count, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0, ans = 0;
        solve(root, k, count, ans);
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
// Way - I (Brute Force [Inorder Traversal (ArrayList)]) : O(n) time and O(n) space
class Solution
{
    void solve(TreeNode root, int k, List<Integer> inorder)
    {
        if (root == null)
            return;
        solve(root.left, k, inorder);
        inorder.add(root.val);
        solve(root.right, k, inorder);
    }

    public int kthSmallest(TreeNode root, int k)
    {
        List<Integer> inorder = new ArrayList<>();
        solve(root, k, inorder);
        return inorder.get(k - 1);
    }
}

// Way - II (Count) : O(n) time and O(1) space
class Solution
{
    void solve(TreeNode root, int k, int []count, int []ans)
    {
        if (root == null)
            return;
        solve(root.left, k, count, ans);
        count[0]++;
        if (count[0] == k)
        {
            ans[0] = root.val;
            return;
        }
        solve(root.right, k, count, ans);
    }

    public int kthSmallest(TreeNode root, int k)
    {
        int []count = new int[1];
        count[0] = 0;
        int []ans = new int[1];
        ans[0] = 0;
        solve(root, k, count, ans);
        return ans[0];
    }
}