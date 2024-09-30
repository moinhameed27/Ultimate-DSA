// Leetcode : https://leetcode.com/problems/house-robber-ii/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(1) space
class Solution
{
    int solve(vector<int> &nums, int idx, int n)
    {
        if (idx >= n)
            return 0;
        // Steal the current house and move to the next to next house
        int steal = nums[idx] + solve(nums, idx + 2, n);
        // Skip the current house and move to the next house
        int skip = solve(nums, idx + 1, n);
        return max(steal, skip);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // If we steal the first house, then we can't take the profit of last house
        int startFirstHouse = solve(nums, 0, n - 1);
        // If we skip the first house, then we can take the profit of last house
        int startSecondHouse = solve(nums, 1, n);
        // Return the maximum of the two
        return max(startFirstHouse, startSecondHouse);
    }
};

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(vector<int> &nums, vector<int> &dp, int idx, int n)
    {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        // Steal the current house and move to the next to next house
        int steal = nums[idx] + solve(nums, dp, idx + 2, n);
        // Skip the current house and move to the next house
        int skip = solve(nums, dp, idx + 1, n);
        return dp[idx] = max(steal, skip);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n + 1, -1);

        // If we steal the first house, then we can't take the profit of last house
        int startFirstHouse = solve(nums, dp, 0, n - 1);
        dp.clear();
        dp.resize(n + 1, -1);

        // If we skip the first house, then we can take the profit of last house
        int startSecondHouse = solve(nums, dp, 1, n);

        return max(startFirstHouse, startSecondHouse);
    }
};

// Way - III (Bottom UP DP) : O(n) time and O(n) space
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        // Start from 1st house and go till n - 1 house
        for (int i = 1; i <= n - 1; i++)
        {
            int steal = nums[i - 1];
            if (i >= 2)
                steal += +dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }
        int startFirstHouse = dp[n - 1];

        dp.clear();
        dp.resize(n + 1, -1);
        dp[0] = 0, dp[1] = 0;
        // Start from 2nd house and go till n house
        for (int i = 2; i <= n; i++)
        {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }
        int startSecondHouse = dp[n];

        // Return the maximum of the two
        return max(startFirstHouse, startSecondHouse);
    }
};

// Way - IV (Bottom UP DP [Constant Space]) : O(n) time and O(1) space
class Solution
{
    int solve(vector<int> &nums, int idx, int n)
    {
        // PREV : Profit till previous house, PREV_PREV : Profit till house before the previous house
        int prev = 0, prev_prev = 0;
        for (int i = idx; i <= n; i++)
        {
            // STEAL : If we steal the current house, then we can't take the profit of previous house, so we add the
            // profit of current house (nums[i]) and profit of house before the previous house (prev_prev)
            int steal = nums[i] + prev_prev;
            // SKIP : If we skip the current house, then we have the profit till previous house (prev)
            int skip = prev;

            int curr = max(steal, skip);
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        
        // If we steal the first house, then we can't take the profit of last house
        int startFirstHouse = solve(nums, 0, n - 2);
        // If we skip the first house, then we can take the profit of last house
        int startSecondHouse = solve(nums, 1, n - 1);

        return max(startFirstHouse, startSecondHouse);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(1) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        // If we steal the first house, then we can't take the profit of last house
        int startFirstHouse = solve(nums, 0, n - 1);
        // If we skip the first house, then we can take the profit of last house
        int startSecondHouse = solve(nums, 1, n);
        // Return the maximum of the two
        return Math.max(startFirstHouse, startSecondHouse);
    }
    
    private int solve(int[] nums, int idx, int n) 
    {
        if(idx >= n) return 0;
        // Steal the current house and move to the next to next house
        int steal = nums[idx] + solve(nums, idx + 2, n);
        // Skip the current house and move to the next house
        int skip = solve(nums, idx + 1, n);
        return Math.max(steal, skip);
    }
}

// Way - II (DP) : O(n) time and O(n) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        
        // If we steal the first house, then we can't take the profit of last house
        int startFirstHouse = solve(nums, dp, 0, n - 1);
        Arrays.fill(dp, -1);
        
        // If we skip the first house, then we can take the profit of last house
        int startSecondHouse = solve(nums, dp, 1, n);
        
        return Math.max(startFirstHouse, startSecondHouse);
    }
    
    private int solve(int[] nums, int[] dp, int idx, int n) 
    {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        // Steal the current house and move to the next to next house
        int steal = nums[idx] + solve(nums, dp, idx + 2, n);
        // Skip the current house and move to the next house
        int skip = solve(nums, dp, idx + 1, n);
        return dp[idx] = Math.max(steal, skip);
    }
}

// Way - III (Bottom UP DP) : O(n) time and O(n) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        if(n == 1) return nums[0];
        
        int[] dp = new int[n + 1];
        dp[0] = 0;
        // Start from 1st house and go till n - 1 house
        for(int i = 1; i <= n - 1; i++)
        {
            int steal = nums[i - 1];
            if(i >= 2) steal += dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = Math.max(steal, skip);
        }
        int startFirstHouse = dp[n - 1];
        
        dp = new int[n + 1];
        dp[0] = 0; dp[1] = 0;
        // Start from 2nd house and go till n house
        for(int i = 2; i <= n; i++)
        {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = Math.max(steal, skip);
        }
        int startSecondHouse = dp[n];
        
        // Return the maximum of the two
        return Math.max(startFirstHouse, startSecondHouse);
    }
}

// Way - IV (Bottom UP DP [Constant Space]) : O(n) time and O(1) space
class Solution 
{
    public int rob(int[] nums) 
    {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        // If we steal the first house, then we can't take the profit of last house
        int startFirstHouse = solve(nums, 0, n - 2);
        // If we skip the first house, then we can take the profit of last house
        int startSecondHouse = solve(nums, 1, n - 1);
        
        return Math.max(startFirstHouse, startSecondHouse);
    }
    
    private int solve(int[] nums, int idx, int n) 
    {
        // PREV : Profit till previous house, PREV_PREV : Profit till house before the previous house
        int prev = 0, prev_prev = 0;
        for(int i = idx; i <= n; i++)
        {
            // STEAL : If we steal the current house, then we can't take the profit of previous house, so we add the
            // profit of current house (nums[i]) and profit of house before the previous house (prev_prev)
            int steal = nums[i] + prev_prev;
            // SKIP : If we skip the current house, then we have the profit till previous house (prev)
            int skip = prev;
            
            int curr = Math.max(steal, skip);
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }
}