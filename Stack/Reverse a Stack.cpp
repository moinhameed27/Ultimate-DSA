// GFG : https://www.geeksforgeeks.org/problems/reverse-a-stack/1

// Way - I (Brute Force [Using Two Stacks])
class Solution
{
public:
    void Reverse(stack<int> &st)
    {
        stack<int> st1, st2;
        while (!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        while (!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
    }
};

// Way - II (Recursion)
class Solution
{
    // Remove the top until stack is empty, then insert the element and then insert the removed top
    void insertAtBottom(stack<int> &st, int element)
    {
        if (st.empty())
        {
            st.push(element);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(top);
    }

public:
    // Remove the top and reverse the remaining stack, then insert the top at the bottom
    void Reverse(stack<int> &st)
    {
        if (st.empty())
            return;
        int top = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, top);
    }
};