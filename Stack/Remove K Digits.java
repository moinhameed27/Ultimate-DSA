// Leetcode : https://leetcode.com/problems/remove-k-digits/description/

// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (k >= n)
            return "0";

        int i = 0;
        while (k > 0 && i < num.size() - 1)
        {
            // If current element is smaller, remove it
            if (num[i] > num[i + 1])
            {
                num.erase(i, 1);
                k--;
                if (i > 0)
                    i--;
            }
            else
                i++;
        }

        // If still there is k left, remove the last k elements
        if (k > 0)
            num.erase(num.size() - k);

        // Remove trailing zeros
        while (!num.empty() && num[0] == '0')
            num.erase(0, 1);

        return num.empty() ? "0" : num;
    }
};

// Way - II (Stack)
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (k >= n)
            return "0";
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int number = num[i] - '0';
            // If current element is smaller than top element of stack, remove it
            while (!st.empty() && number < st.top() && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(number);
        }
        // If there is still k left, remove the last k elements
        while (k > 0)
        {
            st.pop();
            k--;
        }
        // Copy the number from the stack to string
        string ans = "";
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        // Reverse the string as stack will give the number in reverse order
        reverse(ans.begin(), ans.end());

        // Remove trailing zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0')
            start++;
        // Get the substring beginning from start
        ans = ans.substr(start);
        return ans.empty() ? "0" : ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
    public String removeKdigits(String num, int k)
    {
        int n = num.length();
        if (k >= n)
            return "0";

        int i = 0;
        while (k > 0 && i < num.length() - 1)
        {
            // If current element is smaller, remove it
            if (num.charAt(i) > num.charAt(i + 1))
            {
                num = num.substring(0, i) + num.substring(i + 1);
                k--;
                if (i > 0)
                    i--;
            }
            else
                i++;
        }

        // If still there is k left, remove the last k elements
        if (k > 0)
            num = num.substring(0, num.length() - k);

        // Remove trailing zeros
        int start = 0;
        while (start < num.length() && num.charAt(start) == '0')
            start++;
        // Get the substring beginning from start
        num = num.substring(start);
        return num.isEmpty() ? "0" : num;
    }
};

// Way - II (Stack)
class Solution
{
    public String removeKdigits(String num, int k)
    {
        int n = num.length();
        if (k >= n)
            return "0";
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++)
        {
            int number = num.charAt(i) - '0';
            // If current element is smaller than top element of stack, remove it
            while (!st.isEmpty() && number < st.peek() && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(number);
        }
        // If there is still k left, remove the last k elements
        while (k > 0)
        {
            st.pop();
            k--;
        }
        // Copy the number from the stack to string
        StringBuilder ans = new StringBuilder();
        while (!st.isEmpty())
        {
            ans.append(st.pop());
        }
        // Reverse the string as stack will give the number in reverse order
        ans.reverse();

        // Remove trailing zeros
        int start = 0;
        while (start < ans.length() && ans.charAt(start) == '0')
            start++;
        // Get the substring beginning from start
        ans = new StringBuilder(ans.substring(start));
        return ans.length() == 0 ? "0" : ans.toString();
    }
};