// LeetCode : https://leetcode.com/problems/maximum-subarray/

// GFG : https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i, currSum = 0; j < n; j++)
            {
                currSum += nums[j];
                ans = max(currSum, ans);
            }
        }
        return ans;
    }
};

// Way - II (Kadane's Algo)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0, finalSum = INT_MIN;
        for (int i : nums)
        {
            currSum = max(i, currSum + i);
            finalSum = max(finalSum, currSum);
        }
        return finalSum;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE]
class Solution
{
    public int maxSubArray(int[] nums)
    {
        int n = nums.length, ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++)
        {
            for (int j = i, currSum = 0; j < n; j++)
            {
                currSum += nums[j];
                ans = Math.max(currSum, ans);
            }
        }
        return ans;
    }
}

// Way - II (Kadane's Algo)
class Solution
{
    public int maxSubArray(int[] nums)
    {
        int currSum = 0, finalSum = Integer.MIN_VALUE;
        for (int i : nums)
        {
            currSum = Math.max(i, currSum + i);
            finalSum = Math.max(finalSum, currSum);
        }
        return finalSum;
    }
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Dry Run:
nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}
currSum(cS) = 0, finalSum(fS) = INT_MIN

--> i - 0 (nums[0]) (-2)
cS = (-2, 0 + (-2)) = -2
fS = (INT_MIN, -2) = -2

--> i - 1 (nums[1]) (1)
cS = (1, -2 + 1) = 1
fS = (-2, 1) = 1

--> i - 2 (nums[2]) (-3)
cS = (-3, 1 + (-3)) = -2
fS = (1, -2) = 1

--> i - 3 (nums[3]) (4)
cS = (4, -2 + 4) = 4
fS = (1, 4) = 4

--> i - 4 (nums[4]) (-1)
cS = (-1, 4 + (-1)) = 3
fS = (4, 3) = 4

--> i - 5 (nums[5]) (2)
cS = (2, 3 + 2) = 5
fS = (4, 5) = 5

--> i - 6 (nums[6]) (1)
cS = (1, 5 + 1) = 6
fS = (5, 6) = 6

--> i - 7 (nums[7]) (-5)
cS = (-5, 6 + (-5)) = 1
fS = (6, 1) = 6

--> i - 8 (nums[8]) (4)
cS = (4, 1 + 4) = 5
fS = (6, 5) = 1



-----------------------
Reason why current sum is set to 0 and final Sum is set to minimum integer as final sum can have negative value also
nums[1] = {-1}
cS = 0, fS = INT_MIN

--> i - 0 (nums[0]) (-1)
cS = (-1, 0 + (-1)) = -1
fS = (INT_MIN, -1) = -1
*/