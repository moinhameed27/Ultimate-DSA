// Leetcode : https://leetcode.com/problems/house-robber/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(1) space
class Solution
{
    int solve(vector<int> &nums, int n, int idx)
    {
        if (idx >= n)
            return 0;
        // Steal the current house and move to the next to next house
        int steal = nums[idx] + solve(nums, n, idx + 2);
        // Skip the current house and move to the next house
        int skip = solve(nums, n, idx + 1);
        // Return the maximum of the two
        return max(steal, skip);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n, 0);
    }
};

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(vector<int> &nums, vector<int> &dp, int n, int idx)
    {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int steal = nums[idx] + solve(nums, dp, n, idx + 2);
        int skip = solve(nums, dp, n, idx + 1);
        return dp[idx] = max(steal, skip);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, dp, n, 0);
    }
};

// Way - III (Bottom UP DP) : O(n) time and O(n) space
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0, dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            // STEAL : If we steal the current house, then we can't take the profit of previous house, so we add the
            // profit of current house (nums[i - 1]) and profit of house before the previous house (dp[i - 2])
            int steal = nums[i - 1] + dp[i - 2];
            // SKIP : If we skip the current house, then we have the profit till previous house (dp[i - 1])
            int skip = dp[i - 1];

            dp[i] = max(steal, skip);
        }
        return dp[n];
    }
};

// Way - IV (Bottom UP DP [Constant Space]) : O(n) time and O(1) space
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // PREV : Profit till previous house, PREV_PREV : Profit till house before the previous house
        int prev = nums[0], prev_prev = 0;
        for (int i = 2; i <= n; i++)
        {
            // STEAL : If we steal the current house, then we can't take the profit of previous house, so we add the
            // profit of current house (nums[i - 1]) and profit of house before the previous house (prev_prev)
            int steal = nums[i - 1] + prev_prev;
            // SKIP : If we skip the current house, then we have the profit till previous house (prev)
            int skip = prev;
            int curr = max(steal, skip);
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(1) space
class Solution 
{
    public int rob(int[] nums) 
    {
        return solve(nums, nums.length, 0);
    }
    
    private int solve(int[] nums, int n, int idx) 
    {
        if(idx >= n) 
            return 0;
        // Steal the current house and move to the next to next house
        int steal = nums[idx] + solve(nums, n, idx + 2);
        // Skip the current house and move to the next house
        int skip = solve(nums, n, idx + 1);
        // Return the maximum of the two
        return Math.max(steal, skip);
    }
}

// Way - II (DP) : O(n) time and O(n) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(nums, dp, n, 0);
    }
    
    private int solve(int[] nums, int[] dp, int n, int idx) 
    {
        if(idx >= n) 
            return 0;
        if(dp[idx] != -1) 
            return dp[idx];
        int steal = nums[idx] + solve(nums, dp, n, idx + 2);
        int skip = solve(nums, dp, n, idx + 1);
        return dp[idx] = Math.max(steal, skip);
    }
}

// Way - III (Bottom UP DP) : O(n) time and O(n) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++) 
        {
            // STEAL : If we steal the current house, then we can't take the profit of previous house, so we add the
            // profit of current house (nums[i - 1]) and profit of house before the previous house (dp[i - 2])
            int steal = nums[i - 1] + dp[i - 2];
            // SKIP : If we skip the current house, then we have the profit till previous house (dp[i - 1])
            int skip = dp[i - 1];
            dp[i] = Math.max(steal, skip);
        }
        return dp[n];
    }
}

// Way - IV (Bottom UP DP [Constant Space]) : O(n) time and O(1) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        // PREV : Profit till previous house, PREV_PREV : Profit till house before the previous house
        int prev = nums[0], prev_prev = 0;
        for(int i = 2; i <= n; i++) 
        {
            // STEAL : If we steal the current house, then we can't take the profit of previous house, so we add the
            // profit of current house (nums[i - 1]) and profit of house before the previous house (prev_prev)
            int steal = nums[i - 1] + prev_prev;
            // SKIP : If we skip the current house, then we have the profit till previous house (prev)
            int skip = prev;
            int curr = Math.max(steal, skip);
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }
}