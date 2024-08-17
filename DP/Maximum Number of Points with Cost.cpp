// Leetcode : https://leetcode.com/problems/maximum-number-of-points-with-cost/description/
 
// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE] : O(m * n^2) time and O(n) space
class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();
        vector<long long> prev(n);
        // Setting first row as prev
        for (int i = 0; i < n; i++)
            prev[i] = points[0][i];

        for (int i = 1; i < m; i++)
        {
            vector<long long> curr(n, 0);
            // For every column, calculate the maximum value that can be obtained
            for (int j = 0; j < n; j++)
            {
                // Traversing the previous array to calculate the maximum value
                for (int k = 0; k < n; k++)
                    curr[j] = max(curr[j], points[i][j] + prev[k] - abs(j - k));
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};

// Way - II (DP) : O(m * n) time and O(n) space
/*
1. For every row, we need to calculate the maximum value that can be obtained for every column.
2. For every column, find the maximum points it can get on the left side and right side.
3. The maximum value that can be obtained for a column is the maximum of the left and right side.
*/
class Solution
{
public:
    typedef long long ll;
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();
        vector<ll> prev(n);
        // Setting prev as first row
        for (int i = 0; i < n; i++)
            prev[i] = points[0][i];

        for (int i = 1; i < m; i++)
        {
            vector<ll> curr(n, 0);
            vector<ll> prefix = curr, suffix = curr;

            // Calculating the maximum value that can be obtained on the left side for every column
            prefix[0] = prev[0];
            for (int j = 1; j < n; j++)
                prefix[j] = max(prev[j], prefix[j - 1] - 1); // -1 due to column difference

            // Calculating the maximum value that can be obtained on the right side for every column
            suffix[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j--)
                suffix[j] = max(prev[j], suffix[j + 1] - 1);

            for (int j = 0; j < n; j++)
                curr[j] = points[i][j] + max(prefix[j], suffix[j]);

            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE] : O(m * n^2) time and O(n) space
class Solution
{
    public long maxPoints(int[][] points)
    {
        int m = points.length, n = points[0].length;
        long[] prev = new long[n];
        // Setting first row as prev
        for (int i = 0; i < n; i++)
            prev[i] = points[0][i];

        for (int i = 1; i < m; i++)
        {
            long[] curr = new long[n];
            // For every column, calculate the maximum value that can be obtained
            for (int j = 0; j < n; j++)
            {
                // Traversing the previous array to calculate the maximum value
                for (int k = 0; k < n; k++)
                    curr[j] = Math.max(curr[j], points[i][j] + prev[k] - Math.abs(j - k));
            }
            prev = curr;
        }
        return Arrays.stream(prev).max().getAsLong();
    }
}

// Way - II (DP) : O(m * n) time and O(n) space
class Solution
{
    public long maxPoints(int[][] points)
    {
        int m = points.length, n = points[0].length;
        long[] prev = new long[n];
        // Setting prev as first row
        for (int i = 0; i < n; i++)
            prev[i] = points[0][i];

        for (int i = 1; i < m; i++)
        {
            long[] curr = new long[n];
            long[] prefix = new long[n], suffix = new long[n];

            // Calculating the maximum value that can be obtained on the left side for every column
            prefix[0] = prev[0];
            for (int j = 1; j < n; j++)
                prefix[j] = Math.max(prev[j], prefix[j - 1] - 1); // -1 due to column difference

            // Calculating the maximum value that can be obtained on the right side for every column
            suffix[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j--)
                suffix[j] = Math.max(prev[j], suffix[j + 1] - 1);

            for (int j = 0; j < n; j++)
                curr[j] = points[i][j] + Math.max(prefix[j], suffix[j]);

            prev = curr;
        }
        return Arrays.stream(prev).max().getAsLong();
    }
}