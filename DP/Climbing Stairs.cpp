// Leetcode : https://leetcode.com/problems/climbing-stairs/description/

// GFG : https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(n) space
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(int n, vector<int> &dp)
    {
        if (n <= 3)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Way - III (Bottom-Up DP) : O(n) time and O(n) space
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int i = 4; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

// Way - IV (Bottom-Up DP [Constant Space]) : O(n) time and O(1) space
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        int a = 1, b = 2, c = a + b;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(n) space
class Solution
{
    public int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(int n, int[] dp)
    {
        if (n <= 3)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    public int climbStairs(int n)
    {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(n, dp);
    }
}

// Way - III (Bottom-Up DP) : O(n) time and O(n) space
class Solution
{
    public int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
}

// Way - IV (Bottom-Up DP [Constant Space]) : O(n) time and O(1) space
class Solution
{
    public int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        int a = 1, b = 2, c = a + b;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}