// Leetcode : https://leetcode.com/problems/separate-black-and-white-balls/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I : O(n) time and O(1) space
class Solution 
{
public:
    long long minimumSteps(string s) 
    {
        long long swaps = 0;
        int black = 0;
        for(char ch : s)
        {
            if(ch == '1')
                black++;
            // Whenever a white ball comes, we need
            // to swap all the black balls with it
            else
                swaps += black;
        }
        return swaps;
    }
};

// Way - II : O(n) time and O(1) space
class Solution 
{
public:
    long long minimumSteps(string s) 
    {
        int n = s.size();
        long long swaps = 0;
        int white = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
                white++;
            // Whenever a black ball comes, we need
            // to swap all the white balls with it
            else
                swaps += white;
        }
        return swaps;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I : O(n) time and O(1) space
class Solution 
{
    public long minimumSteps(String s) 
    {
        long swaps = 0;
        int black = 0;
        for(char ch : s.toCharArray())
        {
            if(ch == '1')
                black++;
            // Whenever a white ball comes, we need to swap all the black balls with it
            else
                swaps += black;
        }
        return swaps;
    }
}

// Way - II : O(n) time and O(1) space
class Solution 
{
    public long minimumSteps(String s) 
    {
        int n = s.length();
        long swaps = 0;
        int white = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s.charAt(i) == '0')
                white++;
            // Whenever a black ball comes, we need to swap all the white balls with it
            else
                swaps += white;
        }
        return swaps;
    }
}