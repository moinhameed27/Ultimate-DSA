// Leetcode : https://leetcode.com/problems/xor-queries-of-a-subarray/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space (Exclude the space for answer)
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> answer(n);
        for (int i = 0; i < n; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            int XOR = 0;
            for (int i = left; i <= right; i++)
                XOR ^= arr[i];

            answer[i] = XOR;
        }
        return answer;
    }
};

// Way - II (Prefix XOR) : O(n) time and O(m) space
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int m = arr.size(), n = queries.size();
        vector<int> prefixXOR(m), answer(n);
        // Make Prefix XOR Array
        prefixXOR[0] = arr[0];
        for (int i = 1; i < m; i++)
            prefixXOR[i] = arr[i] ^ prefixXOR[i - 1];

        for (int i = 0; i < n; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            // If left is 0, it will have xor from start of array to right, so simply return prefixXOR[right]
            if (left == 0)
                answer[i] = prefixXOR[right];
            // Left is not 0, so we need to deduct the (left - 1) xor from right xor to get the xor from left to right
            else
                answer[i] = prefixXOR[left - 1] ^ prefixXOR[right];
        }
        return answer;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space (Exclude the space for answer)
class Solution
{
    public int[] xorQueries(int[] arr, int[][] queries)
    {
        int n = queries.length;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            int XOR = 0;
            for (int j = left; j <= right; j++)
                XOR ^= arr[j];

            answer[i] = XOR;
        }
        return answer;
    }
}

// Way - II (Prefix XOR) : O(n) time and O(m) space
class Solution
{
    public int[] xorQueries(int[] arr, int[][] queries)
    {
        int m = arr.length, n = queries.length;
        int[] prefixXOR = new int[m], answer = new int[n];
        // Make Prefix XOR Array
        prefixXOR[0] = arr[0];
        for (int i = 1; i < m; i++)
            prefixXOR[i] = arr[i] ^ prefixXOR[i - 1];

        for (int i = 0; i < n; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            // If left is 0, it will have xor from start of array to right, so simply return prefixXOR[right]
            if (left == 0)
                answer[i] = prefixXOR[right];
            // Left is not 0, so we need to deduct the (left - 1) xor from right xor to get the xor from left to right
            else
                answer[i] = prefixXOR[left - 1] ^ prefixXOR[right];
        }
        return answer;
    }
}
