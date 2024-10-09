// Leetcode : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Stack) : O(n) time and O(n) space
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int brackets = 0;
        stack<char> st;
        for (char ch : s)
        {
            if (ch == '(')
                st.push(ch);
            else if (!st.empty()) // Pair matched, passed both
                st.pop();
            else if (st.empty()) // Insertion required
                brackets++;
        }
        return brackets + st.size();
    }
};

// Way - II (Counting) : O(n) time and O(1) space
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int leftBrackets = 0, rightBrackets = 0;
        for (char ch : s)
        {
            if (ch == '(')
                leftBrackets++;
            else if (leftBrackets > 0)  // Pair matched, passed both
                leftBrackets--;
            else if (leftBrackets == 0) // Insertion required
                rightBrackets++;
        }
        return leftBrackets + rightBrackets;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Stack) : O(n) time and O(n) space
class Solution 
{
    public int minAddToMakeValid(String s) 
    {
        int brackets = 0;
        Stack<Character> st = new Stack<>();
        for (char ch : s.toCharArray())
        {
            if (ch == '(')
                st.push(ch);
            else if (!st.empty()) // Pair matched, passed both
                st.pop();
            else if (st.empty()) // Insertion required
                brackets++;
        }
        return brackets + st.size();
    }
}

// Way - II (Counting) : O(n) time and O(1) space
class Solution 
{
    public int minAddToMakeValid(String s) 
    {
        int leftBrackets = 0, rightBrackets = 0;
        for (char ch : s.toCharArray())
        {
            if (ch == '(')
                leftBrackets++;
            else if (leftBrackets > 0)  // Pair matched, passed both
                leftBrackets--;
            else if (leftBrackets == 0) // Insertion required
                rightBrackets++;
        }
        return leftBrackets + rightBrackets;
    }
}