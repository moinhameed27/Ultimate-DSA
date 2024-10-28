// Leetcode : https://leetcode.com/problems/longest-square-streak-in-an-array/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (HashMap + Sorting) : O(nlogn) time and O(n) space
class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int maxStreak = 0;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());

        for (int num : nums)
        {
            int root = (int)sqrt(num);
            // If num is a perfect square and its root is present in the map
            if (root * root == num && mp.find(root) != mp.end())
                mp[num] = mp[root] + 1;
            // Else store the number in the map as streak of 1
            else
                mp[num] = 1;

            maxStreak = max(maxStreak, mp[num]);
        }
        return maxStreak == 1 ? -1 : maxStreak;
    }
};

// Way - II (HashSet) : O(n) time and O(n) space
class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int maxStreak = 0;
        // Store all the numbers in a set
        unordered_set<int> st(nums.begin(), nums.end());

        for (int num : nums)
        {
            int streak = 0;
            long long curr = num;

            // Check if the number is present in the set and keep squaring it for the maximum streak
            while (st.find(curr) != st.end())
            {
                streak++;
                // As given by constraints, the number can be at max 1e5
                if (curr * curr > 1e5)
                    break;
                curr *= curr;
            }

            maxStreak = max(maxStreak, streak);
        }
        return maxStreak == 1 ? -1 : maxStreak;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (HashMap + Sorting) : O(nlogn) time and O(n) space
class Solution 
{
    public int longestSquareStreak(int[] nums) 
    {
        int maxStreak = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        Arrays.sort(nums);
        
        for(int num : nums)
        {
            int root = (int)Math.sqrt(num);
            // If num is a perfect square and its root is present in the map
            if(root * root == num && mp.containsKey(root))
                mp.put(num, mp.get(root) + 1);
            // Else store the number in the map as streak of 1
            else
                mp.put(num, 1);
            
            maxStreak = Math.max(maxStreak, mp.get(num));
        }
        return maxStreak == 1 ? -1 : maxStreak;    
    }
}

// Way - II (HashSet) : O(n) time and O(n) space
class Solution 
{
    public int longestSquareStreak(int[] nums) 
    {
        int maxStreak = 0;
        Set<Integer> st = new HashSet<>();
        for(int num : nums)
            st.add(num);
        
        for(int num : nums)
        {
            int streak = 0;
            long curr = num;
            
            // Check if the number is present in the set and keep squaring it for the maximum streak
            while(st.contains((int)curr))
            {
                streak++;
                // As given by constraints, the number can be at max 1e5
                if(curr * curr > 1e5)
                    break;
                curr *= curr;
            }
            
            maxStreak = Math.max(maxStreak, streak);
        }
        return maxStreak == 1 ? -1 : maxStreak;    
    }
}