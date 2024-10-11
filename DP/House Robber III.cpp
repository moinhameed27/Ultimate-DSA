// Leetcode : https://leetcode.com/problems/house-robber-iii/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
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
// Way - I (Recursion)
class Solution
{
    int solve(TreeNode *root, bool parentRobbed)
    {
        if (!root)
            return 0;
        // If parent is robbed, then we can't rob the current house
        if (parentRobbed)
            return solve(root->left, false) + solve(root->right, false);

        else
        {
            // If parent is not robbed, then we have 2 options, either rob the current house or skip it
            int steal = root->val + solve(root->left, true) + solve(root->right, true);
            int skip = solve(root->left, false) + solve(root->right, false);
            return max(steal, skip);
        }
    }

public:
    int rob(TreeNode *root)
    {
        return solve(root, false);
    }
};

// Way - II (DP)
class Solution
{
    unordered_map<TreeNode *, int> mp_rob;
    unordered_map<TreeNode *, int> mp_no_rob;
    int solve(TreeNode *root, bool parentRobbed)
    {
        if (!root)
            return 0;
        // If parent is robbed, then we can't rob the current house
        if (parentRobbed)
        {
            if (mp_rob.count(root))
                return mp_rob[root];
            return mp_rob[root] = solve(root->left, false) + solve(root->right, false);
        }

        // If parent is not robbed, then we have 2 options, either rob the current house or skip it
        else
        {
            if (mp_no_rob.count(root))
                return mp_no_rob[root];
            int steal = root->val + solve(root->left, true) + solve(root->right, true);
            int skip = solve(root->left, false) + solve(root->right, false);
            return mp_no_rob[root] = max(steal, skip);
        }
    }

public:
    int rob(TreeNode *root)
    {
        return solve(root, false);
    }
};

// Way - III (Better DP)
class Solution
{
    pair<int, int> solve(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        pair<int, int> ans;

        // ans.first -> If current house is robbed
        ans.first = root->val + left.second + right.second;
        // ans.second -> If current house is not robbed
        ans.second = max(left.first, left.second) + max(right.first, right.second);

        return ans;
    }

public:
    int rob(TreeNode *root)
    {
        pair<int, int> ans = solve(root);
        // Return the maximum of the two cases, either root house is robbed or not
        return max(ans.first, ans.second);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
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
// Way - I (Recursion)
class Solution 
{
    public int rob(TreeNode root) 
    {
        return solve(root, false);
    }
    
    private int solve(TreeNode root, boolean parentRobbed) 
    {
        if(root == null) 
            return 0;
        // If parent is robbed, then we can't rob the current house
        if(parentRobbed) 
            return solve(root.left, false) + solve(root.right, false);
        
        // If parent is not robbed, then we have 2 options, either rob the current house or skip it
        int steal = root.val + solve(root.left, true) + solve(root.right, true);
        int skip = solve(root.left, false) + solve(root.right, false);
        return Math.max(steal, skip);
    }
}

// Way - II (DP)
class Solution 
{
    Map<TreeNode, Integer> mp_rob = new HashMap<>();
    Map<TreeNode, Integer> mp_no_rob = new HashMap<>();
    
    public int rob(TreeNode root) 
    {
        return solve(root, false);
    }
    
    private int solve(TreeNode root, boolean parentRobbed) 
    {
        if(root == null) 
            return 0;
        // If parent is robbed, then we can't rob the current house
        if(parentRobbed) 
        {
            if(mp_rob.containsKey(root)) 
                return mp_rob.get(root);
            int ans = solve(root.left, false) + solve(root.right, false);
            mp_rob.put(root, ans);
            return ans;
        }
        
        if(mp_no_rob.containsKey(root)) 
            return mp_no_rob.get(root);
        // If parent is not robbed, then we have 2 options, either rob the current house or skip it
        int steal = root.val + solve(root.left, true) + solve(root.right, true);
        int skip = solve(root.left, false) + solve(root.right, false);

        int ans = Math.max(steal, skip);
        mp_no_rob.put(root, ans);

        return ans;
    }
}

// Way - III (Better DP)
class Solution 
{
    public int rob(TreeNode root) 
    {
        int[] ans = solve(root);
        // Return the maximum of the two cases, either root house is robbed or not
        return Math.max(ans[0], ans[1]);
    }
    
    private int[] solve(TreeNode root) 
    {
        if(root == null) 
            return new int[]{0, 0};
        
        int[] left = solve(root.left);
        int[] right = solve(root.right);
        
        int[] ans = new int[2];
        // ans[0] -> If current house is robbed
        ans[0] = root.val + left[1] + right[1];
        // ans[1] -> If current house is not robbed
        ans[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        
        return ans;
    }
}