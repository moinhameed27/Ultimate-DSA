// GFG : https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Left and Right Array) : O(3N) time and O(3N) Space
class Solution
{
public:
    int findMaxDiff(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> st;
        // Getting the left smaller element for every index
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            left[i] = st.empty() ? 0 : st.top();
            st.push(arr[i]);
        }

        st = stack<int>();

        // Getting the right smaller element for every index
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            right[i] = st.empty() ? 0 : st.top();
            st.push(arr[i]);
        }

        int maxDiff = 0;
        for (int i = 0; i < n; i++)
            maxDiff = max(maxDiff, abs(left[i] - right[i]));

        return maxDiff;
    }
};

// Way - II (Optimized) : O(2N) time and O(2N) Space
class Solution
{
public:
    int findMaxDiff(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ls(n, 0);
        stack<int> st;
        // Getting the left smaller element for every index
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            ls[i] = st.empty() ? 0 : st.top();
            st.push(arr[i]);
        }

        st = stack<int>();
        int maxDiff = 0;

        // Getting the right smaller element for every index and calculating the max Diff at the same time
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            int rs = st.empty() ? 0 : st.top();
            maxDiff = max(maxDiff, abs(ls[i] - rs));
            st.push(arr[i]);
        }

        return maxDiff;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Left and Right Array) : O(3N) time and O(3N) Space
class Solution
{
    public int findMaxDiff(int[] arr)
    {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Stack<Integer> st = new Stack<>();
        // Getting the left smaller element for every index
        for (int i = 0; i < n; i++)
        {
            while (!st.isEmpty() && st.peek() >= arr[i])
                st.pop();
            left[i] = st.isEmpty() ? 0 : st.peek();
            st.push(arr[i]);
        }

        st = new Stack<>();
        // Getting the right smaller element for every index
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.isEmpty() && st.peek() >= arr[i])
                st.pop();
            right[i] = st.isEmpty() ? 0 : st.peek();
            st.push(arr[i]);
        }

        int maxDiff = 0;
        for (int i = 0; i < n; i++)
            maxDiff = Math.max(maxDiff, Math.abs(left[i] - right[i]));

        return maxDiff;
    }
}

// Way - II (Optimized) : O(2N) time and O(2N) Space
class Solution
{
    public int findMaxDiff(int[] arr)
    {
        int n = arr.length;
        int[] ls = new int[n];
        Stack<Integer> st = new Stack<>();
        // Getting the left smaller element for every index
        for (int i = 0; i < n; i++)
        {
            while (!st.isEmpty() && st.peek() >= arr[i])
                st.pop();
            ls[i] = st.isEmpty() ? 0 : st.peek();
            st.push(arr[i]);
        }

        st = new Stack<>();
        int maxDiff = 0;
        // Getting the right smaller element for every index and calculating the max Diff at the same time
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.isEmpty() && st.peek() >= arr[i])
                st.pop();
            int rs = st.isEmpty() ? 0 : st.peek();
            maxDiff = Math.max(maxDiff, Math.abs(ls[i] - rs));
            st.push(arr[i]);
        }

        return maxDiff;
    }
}