// Leetcode : https://leetcode.com/problems/max-consecutive-ones-iii/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [All Substrings]) : O(n ^ 2) time and O(1) space
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int countZeros = 0;
            // If element at j is 0 then increment the count of zeros, if count of zeros is greater than k then break the loop.
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    countZeros++;
                if (countZeros > k)
                    break;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

// Way - II (Sliding Window) : O(n) time and O(1) space
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0, countZeros = 0;
        while (j < n)
        {
            // If element at j is 0 then increment the count of zeros.
            if (nums[j] == 0)
                countZeros++;
            // If count of zeros is greater than k then remove the element at i and increment i until count of zeros is less than or equal to k.
            while (countZeros > k)
            {
                if (nums[i] == 0)
                    countZeros--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [All Substrings]) : O(n ^ 2) time and O(1) space
class Solution
{
    public int longestOnes(int[] nums, int k)
    {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int countZeros = 0;
            // If element at j is 0 then increment the count of zeros, if count of zeros is greater than k then break the loop.
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    countZeros++;
                if (countZeros > k)
                    break;
                ans = Math.max(ans, j - i + 1);
            }
        }
        return ans;
    }
}

// Way - II (Sliding Window) : O(n) time and O(1) space
class Solution
{
    public int longestOnes(int[] nums, int k)
    {
        int n = nums.length;
        int i = 0, j = 0;
        int ans = 0, countZeros = 0;
        while (j < n)
        {
            // If element at j is 0 then increment the count of zeros.
            if (nums[j] == 0)
                countZeros++;
            // If count of zeros is greater than k then remove the element at i and increment i until count of zeros is less than or equal to k.
            while (countZeros > k)
            {
                if (nums[i] == 0)
                    countZeros--;
                i++;
            }
            ans = Math.max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
}