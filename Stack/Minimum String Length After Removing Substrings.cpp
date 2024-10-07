// Leetcode : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (String) : O(n) time and O(n) space
class Solution
{
public:
    int minLength(string s)
    {
        int n = s.size();
        string str;
        for (char &ch : s)
        {
            if (!str.empty() && ch == 'B' && str.back() == 'A')
                str.pop_back();
            else if (!str.empty() && ch == 'D' && str.back() == 'C')
                str.pop_back();
            else
                str += ch;
        }

        return str.size();
    }
};

// Way - II (Stack) : O(n) time and O(n) space
class Solution
{
public:
    int minLength(string s)
    {
        int n = s.size();
        stack<char> st;
        for (char &ch : s)
        {
            if (!st.empty() && ch == 'B' && st.top() == 'A')
                st.pop();
            else if (!st.empty() && ch == 'D' && st.top() == 'C')
                st.pop();
            else
                st.push(ch);
        }

        return st.size();
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (String) : O(n) time and O(n) space
class Solution 
{
    public int minLength(String s) 
    {
        int n = s.length();
        StringBuilder str = new StringBuilder();
        for (char ch : s.toCharArray()) 
        {
            if (str.length() > 0 && ch == 'B' && str.charAt(str.length() - 1) == 'A')
                str.deleteCharAt(str.length() - 1);
            else if (str.length() > 0 && ch == 'D' && str.charAt(str.length() - 1) == 'C')
                str.deleteCharAt(str.length() - 1);
            else 
                str.append(ch);
        }
        return str.length();
    }
}

// Way - II (Stack) : O(n) time and O(n) space
class Solution 
{
    public int minLength(String s) 
    {
        int n = s.length();
        Stack<Character> stack = new Stack<>();
        for (char ch : s.toCharArray()) 
        {
            if (!stack.isEmpty() && ch == 'B' && stack.peek() == 'A')
                stack.pop();
            else if (!stack.isEmpty() && ch == 'D' && stack.peek() == 'C')
                stack.pop();
            else
                stack.push(ch);
        }
        return stack.size();
    }
}