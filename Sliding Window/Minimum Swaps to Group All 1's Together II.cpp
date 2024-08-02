// LeetCode : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

// Way - I (Sliding Window [Extra Space])
/* Count the total number of ones and check that size as a sliding window in the array */
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int swaps = INT_MAX;
        int totalOnes = 0, currOnes = 0;

        vector<int> circularNums(2 * n);
        // Creating a circular array
        for (int i = 0; i < 2 * n; i++)
            circularNums[i] = nums[i % n];

        // Counting total number of ones
        for (int i : nums)
        {
            if (i == 1)
                totalOnes++;
        }

        int i = 0, j = 0;
        while (j < 2 * n)
        {
            if (circularNums[j] == 1)
                currOnes++;

            // If subarray size increases total ones, then we need to shrink the window
            int subArrSize = j - i + 1;
            // Shrink the window and update the current ones if shrinked window had any one
            if (subArrSize > totalOnes)
            {
                currOnes -= circularNums[i];
                i++;
            }
            // Checking for minimum number of ones to swap
            swaps = min(swaps, totalOnes - currOnes);
            j++;
        }
        return swaps;
    }
};

// Way - II (Sliding Window [Constant Space])
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int swaps = INT_MAX;
        int totalOnes = 0, currOnes = 0;

        // Sums the array from 0 index, (Nums contain only 1s and 0s, so total sum will be equal to number of ones)
        totalOnes = accumulate(nums.begin(), nums.end(), 0);
        // for(int i : nums)
        // {
        //     if(i == 1)
        //         totalOnes++;
        // }

        int i = 0, j = 0;
        while (j < 2 * n)
        {
            if (nums[j % n] == 1)
                currOnes++;

            int subArrSize = j - i + 1;
            if (subArrSize > totalOnes)
            {
                currOnes -= nums[i % n];
                i++;
            }
            swaps = min(swaps, totalOnes - currOnes);
            j++;
        }
        return swaps;
    }
};