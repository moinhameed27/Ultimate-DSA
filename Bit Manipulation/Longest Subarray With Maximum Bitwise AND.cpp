// Leetcode : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

/* 
1. The AND of two elements will be <= max(a1, a2).
2. Same Elements will have same AND value.
*/
// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxElement = 0, maxLength = 0, ans = 0;
        for (int num : nums)
        {
            // Got a new bigger element, reset everything
            if (num > maxElement)
            {
                maxElement = num;
                ans = 0;
                maxLength = 0;
            }

            // If the element is equal to the max element, increase the length
            if (num == maxElement)
                maxLength++;
            else
                maxLength = 0;

            ans = max(ans, maxLength);
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public int longestSubarray(int[] nums) 
    {
        int maxElement = 0, maxLength = 0, ans = 0;
        for (int num : nums)
        {
            // Got a new bigger element, reset everything
            if (num > maxElement)
            {
                maxElement = num;
                ans = 0;
                maxLength = 0;
            }

            // If the element is equal to the max element, increase the length
            if (num == maxElement)
                maxLength++;
            else
                maxLength = 0;

            ans = Math.max(ans, maxLength);
        }
        return ans;
    }
}
