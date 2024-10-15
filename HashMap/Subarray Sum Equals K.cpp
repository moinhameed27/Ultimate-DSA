// Leetcode : https://leetcode.com/problems/subarray-sum-equals-k/

// GFG : https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 3) time and O(1) space
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                // Sum of Subarray [i...j]
                for (int K = i; K <= j; K++)
                    sum += nums[K];

                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};

// Way - II (Better) : O(n ^ 2) time and O(1) space
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};

// Way - III (Hashing) : O(n) time and O(n) space
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;
        // Sum is 0 initially, so there is 1 subarray
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (mp.find(sum - k) != mp.end())
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 3) time and O(1) space
class Solution 
{
    public int subarraySum(int[] nums, int k) 
    {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                int sum = 0;
                // Sum of Subarray [i...j]
                for (int K = i; K <= j; K++)
                    sum += nums[K];

                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
}

// Way - II (Better) : O(n ^ 2) time and O(1) space
class Solution 
{
    public int subarraySum(int[] nums, int k) 
    {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            int sum = 0;
            for (int j = i; j < n; j++) 
            {
                sum += nums[j];

                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
}

// Way - III (Hashing) : O(n) time and O(n) space
class Solution 
{
    public int subarraySum(int[] nums, int k) 
    {
        int n = nums.length;
        int sum = 0, ans = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        // Sum is 0 initially, so there is 1 subarray
        mp.put(0, 1);
        for (int i = 0; i < n; i++) 
        {
            sum += nums[i];

            if (mp.containsKey(sum - k))
                ans += mp.get(sum - k);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}