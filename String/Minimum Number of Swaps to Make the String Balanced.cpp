// Leetcode : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Stack) :  O(n) time and O(n) space
class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> st;
        for (char ch : s)
        {
            if (ch == '[')
                st.push(ch);
            else if (!st.empty())
                st.pop();
        }
        return (st.size() + 1) / 2;
    }
};

// Way - II (Simulation) :  O(n) time and O(1) space
class Solution
{
public:
    int minSwaps(string s)
    {
        int brackets = 0;
        for (char ch : s)
        {
            if (ch == '[')
                brackets++;
            else if (brackets > 0) // ch = ']'
                brackets--;
        }
        return ceil((double)brackets / 2);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Stack) :  O(n) time and O(n) space
class Solution 
{
    public int minSwaps(String s) 
    {
        int brackets = 0;
        for (char ch : s.toCharArray())
        {
            if (ch == '[')
                brackets++;
            else if (brackets > 0) // ch = ']'
                brackets--;
        }
        return (brackets + 1) / 2;
    }
}

// Way - II (Simulation) :  O(n) time and O(1) space
class Solution 
{
    public int minSwaps(String s) 
    {
        Stack<Character> st = new Stack<>();
        for (char ch : s.toCharArray())
        {
            if (ch == '[')
                st.push(ch);
            else if (!st.empty()) // ch = ']'
                st.pop();
        }
        return (st.size() + 1) / 2;
    }
}