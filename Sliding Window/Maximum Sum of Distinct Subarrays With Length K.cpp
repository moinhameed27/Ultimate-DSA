// Leetcode : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Sliding Window + HashMap : O(n) time and O(k) space
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long ans = 0, sum = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mp;

        while (j < n)
        {
            mp[nums[j]]++;
            sum += nums[j];

            // Remove the duplicate element from the window
            while (mp[nums[j]] > 1)
            {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            // If the window size is k, update the answer
            if (j - i + 1 == k)
            {
                ans = max(ans, sum);
                mp[nums[i]]--;
                sum -= nums[i++];
            }
            j++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Sliding Window + HashMap : O(n) time and O(k) space
class Solution 
{
    public long maximumSubarraySum(int[] nums, int k) 
    {
        int n = nums.length;
        long ans = 0, sum = 0;
        int i = 0, j = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        
        while(j < n)
        {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            sum += nums[j];
            
            // Remove the duplicate element from the window
            while(mp.get(nums[j]) > 1)
            {
                mp.put(nums[i], mp.get(nums[i]) - 1);
                sum -= nums[i];
                i++;
            }
            
            // If the window size is k, update the answer
            if(j - i + 1 == k)
            {
                ans = Math.max(ans, sum);
                mp.put(nums[i], mp.get(nums[i]) - 1);
                sum -= nums[i++];
            }
            j++;
        }
        return ans;
    }
}