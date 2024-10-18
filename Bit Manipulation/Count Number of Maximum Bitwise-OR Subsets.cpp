// Leetcode : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2 ^ n) time and O(1) space
class Solution
{
    int countSubsets(vector<int> &nums, int n, int maxOR, int idx, int currOR)
    {
        if (idx == n)
        {
            if (currOR == maxOR)
                return 1;
            return 0;
        }

        int include = countSubsets(nums, n, maxOR, idx + 1, currOR | nums[idx]);
        int skip = countSubsets(nums, n, maxOR, idx + 1, currOR);

        return include + skip;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size(), maxOR = 0;
        // Find the maximum OR of all the elements
        for (int num : nums)
            maxOR |= num;

        // Count the number of subsets with maximum OR
        return countSubsets(nums, n, maxOR, 0, 0);
    }
};

// Way - II (DP) : O(n * maxOR) time and O(1) space
class Solution
{
    int countSubsets(vector<int> &nums, int n, int maxOR, int idx, int currOR, vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            if (currOR == maxOR)
                return 1;
            return 0;
        }

        if (dp[idx][currOR] != -1)
            return dp[idx][currOR];

        int include = countSubsets(nums, n, maxOR, idx + 1, currOR | nums[idx], dp);
        int skip = countSubsets(nums, n, maxOR, idx + 1, currOR, dp);

        return dp[idx][currOR] = include + skip;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size(), maxOR = 0;
        for (int num : nums)
            maxOR |= num;

        vector<vector<int>> dp(n + 1, vector<int>(maxOR + 1, -1));

        return countSubsets(nums, n, maxOR, 0, 0, dp);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2 ^ n) time and O(1) space
class Solution
{
    int countSubsets(int[] nums, int n, int maxOR, int idx, int currOR)
    {
        if (idx == n)
        {
            if (currOR == maxOR)
                return 1;
            return 0;
        }

        int include = countSubsets(nums, n, maxOR, idx + 1, currOR | nums[idx]);
        int skip = countSubsets(nums, n, maxOR, idx + 1, currOR);

        return include + skip;
    }

    public int countMaxOrSubsets(int[] nums)
    {
        int n = nums.length, maxOR = 0;
        for (int num : nums)
            maxOR |= num;

        return countSubsets(nums, n, maxOR, 0, 0);
    }
}

// Way - II (DP) : O(n * maxOR) time and O(1) space
class Solution
{
    int countSubsets(int[] nums, int n, int maxOR, int idx, int currOR, int[][] dp)
    {
        if (idx == n)
        {
            if (currOR == maxOR)
                return 1;
            return 0;
        }

        if (dp[idx][currOR] != -1)
            return dp[idx][currOR];

        int include = countSubsets(nums, n, maxOR, idx + 1, currOR | nums[idx], dp);
        int skip = countSubsets(nums, n, maxOR, idx + 1, currOR, dp);

        return dp[idx][currOR] = include + skip;
    }

    public int countMaxOrSubsets(int[] nums)
    {
        int n = nums.length, maxOR = 0;
        for (int num : nums)
            maxOR |= num;

        int[][] dp = new int[n + 1][maxOR + 1];
        for (int[] d : dp)
            Arrays.fill(d, -1);

        return countSubsets(nums, n, maxOR, 0, 0, dp);
    }
}