// Leetcode : https://leetcode.com/problems/missing-number/description/

// GFG : https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting])
/* Sort the array and find the missing number between 1 to n */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};

// Way - II (Vector)
/* Initialize the array of n + 1 with -1. Assign any value to the given array numbers. The -1 value number is the missing number */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n + 1, -1);

        for (int i = 0; i < n; i++)
            v[nums[i]] = nums[i];

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == -1)
                return i;
        }
        return 0;
    }
};

// Way - III (XOR)
/* First, XOR value with 1 to n, then XOR same value with array elements. The missing number will be the final value. */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++)
            ans ^= i;

        for (int i : nums)
            ans ^= i;
        return ans;
    }
};

// Way - IV (Sum)
/* The sum of first n elements is (n (n + 1) / 2). Subtract all the array elements from sum. Remaining value is the missing element. */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int total = (n * (n + 1) / 2);
        for (int i : nums)
            total -= i;
        return total;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting])
/* Sort the array and find the missing number between 1 to n */
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i)
                return i;
        }
        return n;
    }
}

// Way - II (Vector)
/* Initialize the array of n + 1 with -1. Assign any value to the given array numbers. The -1 value number is the missing number */
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int[] v = new int[n + 1];
        Arrays.fill(v, -1);
        
        for(int i = 0; i < n; i++)
            v[nums[i]] = nums[i];
        
        for(int i = 0; i < v.length; i++){
            if(v[i] == -1)
                return i;
        }
        return 0;
    }
}

// Way - III (XOR)
/* First, XOR value with 1 to n, then XOR same value with array elements. The missing number will be the final value. */
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
            ans ^= i;
        
        for(int i : nums)
            ans ^= i;
        return ans;
    }
}

// Way - IV (Sum)
/* The sum of first n elements is (n (n + 1) / 2). Subtract all the array elements from sum. Remaining value is the missing element. */
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int total = (n * (n + 1) / 2);
        for(int i : nums)
            total -= i;
        return total;
    }
}