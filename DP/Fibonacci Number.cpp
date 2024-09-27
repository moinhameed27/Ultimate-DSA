// Leetcode : https://leetcode.com/problems/fibonacci-number/description/

// GFG : https://www.geeksforgeeks.org/problems/the-nth-fibonnaci3150/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(n) space
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Way - III (Bottom - Up DP) : O(n) time and O(n) space
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

// Way - IV (Constant Space) : O(n) time and O(1) space
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int a = 0, b = 1, c = a + b;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(n) space
class Solution
{
    public int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
}

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    private int solve(int n, int[] dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

    public int fib(int n)
    {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(n, dp);
    }
}

// Way - III (Bottom - Up DP) : O(n) time and O(n) space
class Solution
{
    public int fib(int n)
    {
        if (n <= 1)
            return n;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
}

// Way - IV (Constant Space) : O(n) time and O(1) space
class Solution
{
    public int fib(int n)
    {
        if (n <= 1)
            return n;
        int a = 0, b = 1, c = a + b;
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}