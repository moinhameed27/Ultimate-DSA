// Leetcode : https://leetcode.com/problems/single-number/description/

// GFG : https://www.geeksforgeeks.org/problems/single-number1014/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Hashing [Frequency Count]) : O(n) time and O(n) space
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        // Frequency Count
        for (int num : nums)
            freq[num]++;
        // Find the number with frequency 1
        for (auto it : freq)
        {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }
};

// Way - II (XOR) : O(n) time and O(1) space
/* XOR of numbers with even count is 0. */
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int &num : nums)
            ans ^= num;
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Hashing [Frequency Count]) : O(n) time and O(n) space
class Solution
{
    public int singleNumber(int[] nums)
    {
        Map<Integer, Integer> freq = new HashMap<>();
        // Frequency Count
        for (int num : nums)
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        // Find the number with frequency 1
        for (Map.Entry<Integer, Integer> entry : freq.entrySet())
        {
            if (entry.getValue() == 1)
                return entry.getKey();
        }
        return -1;
    }
}

// Way - II (XOR) : O(n) time and O(1) space
/* XOR of numbers with even count is 0. */
class Solution
{
    public int singleNumber(int[] nums)
    {
        int ans = 0;
        for (int num : nums)
            ans ^= num;
        return ans;
    }
}