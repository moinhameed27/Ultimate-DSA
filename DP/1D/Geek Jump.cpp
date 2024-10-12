// GFG : https://www.geeksforgeeks.org/problems/geek-jump/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(1) space
class Solution
{
    int solve(vector<int> &height, int n, int idx)
    {
        if (idx == n - 1)
            return 0;
        int oneStep = INT_MAX, twoSteps = INT_MAX;
        if (idx + 1 < n)
            oneStep = abs(height[idx] - height[idx + 1]) + solve(height, n, idx + 1);
        if (idx + 2 < n)
            twoSteps = abs(height[idx] - height[idx + 2]) + solve(height, n, idx + 2);
        return min(oneStep, twoSteps);
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        return solve(height, n, 0);
    }
};

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(vector<int> &height, int n, int idx, vector<int> &dp)
    {
        if (idx == n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int oneStep = INT_MAX, twoSteps = INT_MAX;
        if (idx + 1 < n)
            oneStep = abs(height[idx] - height[idx + 1]) + solve(height, n, idx + 1, dp);
        if (idx + 2 < n)
            twoSteps = abs(height[idx] - height[idx + 2]) + solve(height, n, idx + 2, dp);

        return dp[idx] = min(oneStep, twoSteps);
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, -1);
        return solve(height, n, 0, dp);
    }
};

// Way - III (Bottom-Up DP) : O(n) time and O(n) space
class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        if(n == 1)
            return 0;
        vector<int> dp(n, -1);
        // dp[i] = Minimum energy required to reach i-th index
        dp[0] = 0, dp[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            // One step from i-1 or two steps from i-2
            int oneStep = dp[i - 1] + abs(height[i] - height[i - 1]);
            int twoSteps = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(oneStep, twoSteps);
        }

        return dp[n - 1];
    }
};

// Way - IV (Better Bottom-Up DP) : O(n) time and O(1) space
class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        if (n == 1)
            return 0;
        // dp[i] = Minimum energy required to reach i-th index
        int prev = abs(height[0] - height[1]), prev_prev = 0;
        for (int i = 2; i < n; i++)
        {
            // One step from i-1 or two steps from i-2
            int oneStep = prev + abs(height[i] - height[i - 1]);
            int twoSteps = prev_prev + abs(height[i] - height[i - 2]);

            prev_prev = prev;
            prev = min(oneStep, twoSteps);
        }

        return prev;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(2^n) time and O(1) space
class Solution
{
    int solve(int[] height, int n, int idx)
    {
        if (idx == n - 1)
            return 0;
        int oneStep = Integer.MAX_VALUE, twoSteps = Integer.MAX_VALUE;
        if (idx + 1 < n)
            oneStep = Math.abs(height[idx] - height[idx + 1]) + solve(height, n, idx + 1);
        if (idx + 2 < n)
            twoSteps = Math.abs(height[idx] - height[idx + 2]) + solve(height, n, idx + 2);
        return Math.min(oneStep, twoSteps);
    }

    public int minimumEnergy(int[] height, int n)
    {
        return solve(height, n, 0);
    }
}

// Way - II (DP) : O(n) time and O(n) space
class Solution
{
    int solve(int[] height, int n, int idx, int[] dp)
    {
        if (idx == n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int oneStep = Integer.MAX_VALUE, twoSteps = Integer.MAX_VALUE;
        if (idx + 1 < n)
            oneStep = Math.abs(height[idx] - height[idx + 1]) + solve(height, n, idx + 1, dp);
        if (idx + 2 < n)
            twoSteps = Math.abs(height[idx] - height[idx + 2]) + solve(height, n, idx + 2, dp);

        return dp[idx] = Math.min(oneStep, twoSteps);
    }

    public int minimumEnergy(int[] height, int n)
    {
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return solve(height, n, 0, dp);
    }
}

// Way - III (Bottom-Up DP) : O(n) time and O(n) space
class Solution
{
    public int minimumEnergy(int[] height, int n)
    {
        if(n == 1)
            return 0;
        int[] dp = new int[n];
        // dp[i] = Minimum energy required to reach i-th index
        dp[0] = 0;
        dp[1] = Math.abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            // One step from i-1 or two steps from i-2
            int oneStep = dp[i - 1] + Math.abs(height[i] - height[i - 1]);
            int twoSteps = dp[i - 2] + Math.abs(height[i] - height[i - 2]);
            dp[i] = Math.min(oneStep, twoSteps);
        }

        return dp[n - 1];
    }
}

// Way - IV (Better Bottom-Up DP) : O(n) time and O(1) space
class Solution
{
    public int minimumEnergy(int[] height, int n)
    {
        if (n == 1)
            return 0;
        // dp[i] = Minimum energy required to reach i-th index
        int prev = Math.abs(height[0] - height[1]), prev_prev = 0;
        for (int i = 2; i < n; i++)
        {
            // One step from i-1 or two steps from i-2
            int oneStep = prev + Math.abs(height[i] - height[i - 1]);
            int twoSteps = prev_prev + Math.abs(height[i] - height[i - 2]);

            prev_prev = prev;
            prev = Math.min(oneStep, twoSteps);
        }

        return prev;
    }
}