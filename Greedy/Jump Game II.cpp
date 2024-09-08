// Leetcode : https://leetcode.com/problems/jump-game-ii/description/

// GFG : https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion + Memoization)
class Solution
{
public:
    int solve(vector<int> &nums, int idx, vector<int> &dp)
    {
        // If reached the end, no jumps required
        if (idx >= nums.size() - 1)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        // Maximum point we can reach from current index
        int reach = idx + nums[idx], jumps = 1e5;
        // Check for all possible indices between [idx+1, reach]
        for (int k = idx + 1; k <= reach; k++)
            jumps = min(jumps, 1 + solve(nums, k, dp));
        return dp[idx] = jumps;
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};

// Way - II (Greedy)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // Greedy Algorithm
        int current = 0, jumps = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, nums[i] + i);
            // All paths are exhausted and a path is to be chosen from them
            if (current == i)
            {
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};

// Way - III (Greedy [Range Checking])
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;
        while (r < n - 1)
        {
            int farthest = 0;
            // Find the farthest point we can reach from current range
            for (int i = l; i <= r; i++)
                farthest = max(farthest, i + nums[i]);
            l = r + 1;  // Move left to one point next to right
            r = farthest;   // Update right to farthest point
            jumps++;    // Increment jumps
        }
        return jumps;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion + Memoization)
class Solution
{
    public int solve(int[] nums, int idx, int[] dp)
    {
        // If reached the end, no jumps required
        if (idx >= nums.length - 1)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        // Maximum point we can reach from current index
        int reach = idx + nums[idx], jumps = 100000;
        // Check for all possible indices between [idx+1, reach]
        for (int k = idx + 1; k <= reach; k++)
            jumps = Math.min(jumps, 1 + solve(nums, k, dp));
        return dp[idx] = jumps;
    }
    public int jump(int[] nums)
    {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return solve(nums, 0, dp);
    }
}

// Way - II (Greedy)
class Solution
{
    public int jump(int[] nums)
    {
        // Greedy Algorithm
        int current = 0, jumps = 0, farthest = 0;
        for (int i = 0; i < nums.length - 1; i++)
        {
            farthest = Math.max(farthest, nums[i] + i);
            // All paths are exhausted and a path is to be chosen from them
            if (current == i)
            {
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }
}

// Way - III (Greedy [Range Checking])
class Solution
{
    public int jump(int[] nums)
    {
        int n = nums.length;
        int jumps = 0, l = 0, r = 0;
        while (r < n - 1)
        {
            int farthest = 0;
            // Find the farthest point we can reach from current range
            for (int i = l; i <= r; i++)
                farthest = Math.max(farthest, i + nums[i]);
            l = r + 1;  // Move left to one point next to right
            r = farthest;   // Update right to farthest point
            jumps++;    // Increment jumps
        }
        return jumps;
    }
}