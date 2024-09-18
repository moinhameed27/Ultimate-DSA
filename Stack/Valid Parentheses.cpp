// LeetCode : https://leetcode.com/problems/valid-parentheses/description/

// GFG : https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            // If there's open bracket, push into stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            // Closing Bracket
            else
            {
                // If stack is empty, open bracket can't be closed
                if (st.empty())
                    return false;
                // If brackets matches
                else if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else if (s[i] == ']' && st.top() == '[')
                    st.pop();
                else if (s[i] == '}' && st.top() == '{')
                    st.pop();
                // brackets don't match
                else
                    return false;
            }
        }
        return st.empty();
    }
};

// Way - II
class Solution
{
    bool isPair(char top, char curr)
    {
        // Pair of braces
        return (top == '(' && curr == ')') ||
               (top == '{' && curr == '}') ||
               (top == '[' && curr == ']');
    }

public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char curr : s)
        {
            // If stack is not empty, check for cases
            if (!st.empty())
            {
                char top = st.top();
                // If brackets match, remove from stack and go to next bracket
                if (isPair(top, curr))
                {
                    st.pop();
                    continue;
                }
            }
            // Push into stack in case of empty stack
            st.push(curr);
        }
        return st.empty();
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I
class Solution 
{
    public boolean isValid(String s) 
    {
        Stack<Character> st = new Stack<>();
        int n = s.length();
        
        for (int i = 0; i < n; i++) 
        {
            char ch = s.charAt(i);
            
            // If it's an opening bracket, push to stack
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            // If it's a closing bracket
            else 
            {
                // Stack empty means there's no opening bracket to match with
                if (st.isEmpty())
                    return false;
                
                // Check if the top of the stack matches the current closing bracket
                char top = st.peek();
                if ((ch == ')' && top == '(') || 
                    (ch == ']' && top == '[') || 
                    (ch == '}' && top == '{'))
                    st.pop();
                // If they don't match
                else 
                    return false;
            }
        }
        
        // If stack is empty, all brackets were matched properly
        return st.isEmpty();
    }
}

// Way - II
class Solution 
{
    // Helper function to check if current closing bracket matches top of stack
    private boolean isPair(char top, char curr) 
    {
        return (top == '(' && curr == ')') ||
               (top == '{' && curr == '}') ||
               (top == '[' && curr == ']');
    }

    public boolean isValid(String s) 
    {
        Stack<Character> st = new Stack<>();
        
        for (char curr : s.toCharArray()) 
        {
            // If stack is not empty, check for pair
            if (!st.isEmpty()) 
            {
                char top = st.peek();
                
                // If current closing bracket matches the top opening bracket, pop from stack
                if (isPair(top, curr)) 
                {
                    st.pop();
                    continue;
                }
            }
            // Otherwise, push the current bracket to stack
            st.push(curr);
        }
        
        // If stack is empty, all brackets were matched properly
        return st.isEmpty();
    }
}