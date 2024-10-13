// GFG : https://www.geeksforgeeks.org/problems/minimal-cost/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(k^n) time and O(1) space
class Solution
{
    int solve(vector<int> &arr, int k, int n, int idx)
    {
        // Reached at the end, no further cost
        if (idx == n - 1)
            return 0;
        // If index is out of bound
        if (idx >= n)
            return 1e7;

        int minCost = INT_MAX;
        // Check for all k possible jumps
        for (int i = 1; i <= k; i++)
        {
            int newIdx = idx + i;
            int curr = abs(arr[idx] - arr[newIdx]);
            minCost = min(minCost, curr + solve(arr, k, n, newIdx));
        }
        return minCost;
    }

public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        return solve(arr, k, n, 0);
    }
};

// Way - II (DP) : O(n*k) time and O(n) space
class Solution
{
    int solve(vector<int> &arr, int k, int n, int idx, vector<int> &dp)
    {
        if (idx == n - 1)
            return 0;
        if (idx >= n)
            return 1e7;

        if (dp[idx] != -1)
            return dp[idx];

        int minCost = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            int newIdx = idx + i;
            int curr = abs(arr[idx] - arr[newIdx]);
            minCost = min(minCost, curr + solve(arr, k, n, newIdx, dp));
        }
        return dp[idx] = minCost;
    }

public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(arr, k, n, 0, dp);
    }
};

// Way - III (Bottom-Up DP) : O(n*k) time and O(n) space
/* dp[i] --> Minimum cost to reach ith index */
class Solution
{
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k && (i + j) < n; j++)
                dp[i + j] = min(dp[i + j], dp[i] + abs(arr[i] - arr[i + j]));
        }
        return dp[n - 1];
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion) : O(k^n) time and O(1) space
class Solution
{
    int solve(int[] arr, int k, int n, int idx)
    {
        if (idx == n - 1)
            return 0;
        if (idx >= n)
            return 1e7;

        int minCost = Integer.MAX_VALUE;
        for (int i = 1; i <= k; i++)
        {
            int newIdx = idx + i;
            int curr = Math.abs(arr[idx] - arr[newIdx]);
            minCost = Math.min(minCost, curr + solve(arr, k, n, newIdx));
        }
        return minCost;
    }

    public int minimizeCost(int k, int[] arr)
    {
        int n = arr.length;
        return solve(arr, k, n, 0);
    }
}

// Way - II (DP) : O(n*k) time and O(n) space
class Solution 
{
    int solve(int arr[], int k, int n, int idx, int dp[])
    {
        if (idx == n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int minCost = Integer.MAX_VALUE;
        for (int i = 1; i <= k && (idx + i < n); i++)
        {
            int newIdx = idx + i;
            int curr = Math.abs(arr[idx] - arr[newIdx]);
            minCost = Math.min(minCost, curr + solve(arr, k, n, newIdx, dp));
        }
        return dp[idx] = minCost;
    }
    public int minimizeCost(int k, int arr[]) 
    {
        int n = arr.length;
        int dp[] = new int[n];
        Arrays.fill(dp, -1);
        return solve(arr, k, n, 0, dp);
    }
}

// Way - III (Bottom-Up DP) : O(n*k) time and O(n) space
class Solution 
{
    public int minimizeCost(int k, int arr[]) 
    {
        int n = arr.length;
        int dp[] = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k && (i + j) < n; j++)
                dp[i + j] = Math.min(dp[i + j], dp[i] + Math.abs(arr[i] - arr[i + j]));
        }
        return dp[n - 1];
    }
}