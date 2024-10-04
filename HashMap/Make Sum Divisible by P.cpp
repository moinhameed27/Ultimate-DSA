// Leetcode : https://leetcode.com/problems/make-sum-divisible-by-p/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
/*
Approach:
* We need to find the minimum length of subarray which makes the array divisible by p on it's deduction.
* sum of arr[i...j] = sum of arr[0...j] - sum of arr[0...i-1]
* target = curr - prev
* prev = curr - target
* prev % p = (curr - target) % p = (curr % p - target % p + p) % p
*/
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        long totalSum = 0;
        // Calculating total sum of array
        for (int num : nums)
            totalSum += num;

        int target = totalSum % p;
        // If the total sum of array is divisible by p, then no need to remove any element
        if (target == 0)
            return 0;

        unordered_map<int, int> prefixMod;  // prefixSum % p -> index
        prefixMod[0] = -1;  // At start, prefix sum is 0
        long prefixSum = 0;
        int minLength = n;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            int currentMod = prefixSum % p;
            int targetMod = (currentMod - target + p) % p;

            // If the prefix sum is divisible by p, then we can remove the subarray [0...i]
            if (prefixMod.find(targetMod) != prefixMod.end())
                minLength = min(minLength, i - prefixMod[targetMod]);

            prefixMod[currentMod] = i;
        }

        // If the minimum length of subarray is equal to n, then no subarray is found
        return minLength == n ? -1 : minLength;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public int minSubarray(int[] nums, int p) 
    {
        int n = nums.length;
        long totalSum = 0;
        // Calculating total sum of array
        for(int num : nums)
            totalSum += num;
        
        int target = (int)(totalSum % p);
        // If the total sum of array is divisible by p, then no need to remove any element
        if(target == 0) return 0;
        
        Map<Integer, Integer> prefixMod = new HashMap<>();  // prefixSum % p -> index
        prefixMod.put(0, -1);  // At start, prefix sum is 0
        long prefixSum = 0;
        int minLength = n;
        
        for(int i = 0; i < n; i++) 
        {
            prefixSum += nums[i];
            int currentMod = (int)(prefixSum % p);
            int targetMod = (currentMod - target + p) % p;
            
            // If the prefix sum is divisible by p, then we can remove the subarray [0...i]
            if(prefixMod.containsKey(targetMod))
                minLength = Math.min(minLength, i - prefixMod.get(targetMod));
            
            prefixMod.put(currentMod, i);
        }
        
        // If the minimum length of subarray is equal to n, then no subarray is found
        return minLength == n ? -1 : minLength;
    }
}