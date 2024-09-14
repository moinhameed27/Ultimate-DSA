// Leetcode : https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// GFG : https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Positve and Negative Arrays]) : O(n) time and O(n) space
#include <vector>

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> positiveNumbers;
        vector<int> negativeNumbers;
        vector<int> finalArray(size);

        for (int i : nums)
        {
            if (i >= 0)
                positiveNumbers.push_back(i);
            else
                negativeNumbers.push_back(i);
        }

        int p = 0, n = 0;

        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
                finalArray[i] = positiveNumbers[p++];
            else
                finalArray[i] = negativeNumbers[n++];
        }

        return finalArray;
    }
};

// Way - II (Two Pointers) : O(n) time and O(1) space (Extra space for finalArray)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> finalArray(size);

        int p = 0, n = 1;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
            {
                finalArray[p] = nums[i];
                p += 2;
            }
            else
            {
                finalArray[n] = nums[i];
                n += 2;
            }
        }

        return finalArray;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Positve and Negative Arrays]) : O(n) time and O(n) space
class Solution 
{
    public int[] rearrangeArray(int[] nums) 
    {
        int size = nums.length;
        List<Integer> positiveNumbers = new ArrayList<>();
        List<Integer> negativeNumbers = new ArrayList<>();
        int[] finalArray = new int[size];
        
        for(int i : nums)
        {
            if(i >= 0)
                positiveNumbers.add(i);
            else
                negativeNumbers.add(i);
        }
        
        int p = 0, n = 0;
        
        for(int i = 0; i < size; i++)
        {
            if(i % 2 == 0)
                finalArray[i] = positiveNumbers.get(p++);
            else
                finalArray[i] = negativeNumbers.get(n++);
        }
        
        return finalArray;    
    }
}

// Way - II (Two Pointers) : O(n) time and O(1) space (Extra space for finalArray)
class Solution 
{
    public int[] rearrangeArray(int[] nums) 
    {
        int size = nums.length;
        int[] finalArray = new int[size];
        
        int p = 0, n = 1;
        for(int i = 0; i < size; i++)
        {
            if(nums[i] > 0)
            {
                finalArray[p] = nums[i];
                p += 2;
            }
            else
            {
                finalArray[n] = nums[i];
                n += 2;
            }
        }
        
        return finalArray;    
    }
}
