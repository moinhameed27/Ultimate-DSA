// Leetcode : https://leetcode.com/problems/longest-valid-parentheses/description/

// GFG : https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (String)
/*
1. Traverse the string from left to right.
2. If opening bracket is found, increment the openingBrackets counter.
3. If closing bracket is found, increment the closingBrackets counter.
4. If both are equal, update the answer as the maximum of answer and 2*openingBrackets.
5. If closing brackets are more than opening brackets, reset both counters as a new subarray will start from here.
6. Repeat the above steps for backward iteration also.
*/
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), ans = 0;
        int openingBrackets = 0, closingBrackets = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                openingBrackets++;
            else
                closingBrackets++;

            // If brackets are equal, then update the answer as subarray is found with valid parentheses
            if (openingBrackets == closingBrackets)
                ans = max(ans, openingBrackets * 2);
            // If closing brackets are more, reset both as a new subarray will start from here
            if (closingBrackets > openingBrackets)
                openingBrackets = closingBrackets = 0;
        }

        // Reset the counters for the next backward iteration
        // Backward iteration is needed in cases like "(()", where opening brackets are more than closing brackets
        openingBrackets = closingBrackets = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                openingBrackets++;
            else
                closingBrackets++;

            // If brackets are equal, then update the answer as subarray is found with valid parentheses
            if (openingBrackets == closingBrackets)
                ans = max(ans, openingBrackets * 2);
            // If opening brackets are more, reset both as a new subarray will start from here
            if (openingBrackets > closingBrackets)
                openingBrackets = closingBrackets = 0;
        }
        return ans;
    }
};

// Way - II (Stack)
/*
1. Push indices in the stack.
2. If opening bracket is found, push the current index.
3. If closing bracket is found, pop the top element.
4. If stack is empty, push the current index.
5. Else, update the answer as the difference of current index and top element of stack.
*/
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), ans = 0;
        stack<int> st;
        st.push(-1); // Push -1 as a base case
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (String)
class Solution
{
    public int longestValidParentheses(String s)
    {
        int n = s.length(), ans = 0;
        int openingBrackets = 0, closingBrackets = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.charAt(i) == '(')
                openingBrackets++;
            else
                closingBrackets++;

            if (openingBrackets == closingBrackets)
                ans = Math.max(ans, openingBrackets * 2);
            if (closingBrackets > openingBrackets)
                openingBrackets = closingBrackets = 0;
        }

        openingBrackets = closingBrackets = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.charAt(i) == '(')
                openingBrackets++;
            else
                closingBrackets++;

            if (openingBrackets == closingBrackets)
                ans = Math.max(ans, openingBrackets * 2);
            if (openingBrackets > closingBrackets)
                openingBrackets = closingBrackets = 0;
        }
        return ans;
    }
}

// Way - II (Stack)
class Solution
{
    public int longestValidParentheses(String s)
    {
        int n = s.length(), ans = 0;
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s.charAt(i) == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.isEmpty())
                    st.push(i);
                else
                    ans = Math.max(ans, i - st.peek());
            }
        }
        return ans;
    }
}