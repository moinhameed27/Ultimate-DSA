// Leetcode : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        // Store the remainder of each element along with its frequency
        for (int num : arr)
        {
            int rem = (num % k + k) % k;
            mp[rem]++;
        }

        // If the frequency of elements with remainder 0 is odd, return falsee e.g {5, 10, 15, 20}
        if (mp[0] % 2 != 0)
            return false;

        // Check for half k pairs
        for (int rem = 1; rem <= k / 2; rem++)
        {
            int counterPart = k - rem;
            // Frequency of both counterPart and remainder should be same to make pairs
            if (mp[counterPart] != mp[rem])
                return false;
        }
        return true;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public boolean canArrange(int[] arr, int k) 
    {
        Map<Integer, Integer> map = new HashMap<>();
        // Store the remainder of each element along with its frequency
        for (int num : arr) 
        {
            int rem = (num % k + k) % k;
            map.put(rem, map.getOrDefault(rem, 0) + 1);
        }

        // If the frequency of elements with remainder 0 is odd, return falsee e.g {5, 10, 15, 20}
        if (map.getOrDefault(0, 0) % 2 != 0)
            return false;
        
        // Check for half k pairs
        for (int rem = 1; rem <= k / 2; rem++) 
        {
            int counterPart = k - rem;
            // Frequency of both counterPart and remainder should be same to make pairs
            if (map.getOrDefault(counterPart, 0) != map.getOrDefault(rem, 0))
                return false;
        }
        return true;
    }
}