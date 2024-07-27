// GFG : https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Way - I (Brute Force)
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans;
        for (int i = 0; i < n; i++)
        {
            long long greater = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    greater = arr[j];
                    break;
                }
            }
            ans.push_back(greater);
        }
        return ans;
    }
};

// Way - II (Stack)
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> st;
        vector<long long> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            // If element on the top is less than the current element then pop the element, remove from stack
            while (!st.empty() && arr[i] >= st.top())
                st.pop();
            // If stack is empty means, no element is greater than current element, simply put -1
            ans[i] = st.empty() ? -1 : st.top();
            // Push current element into stack
            st.push(arr[i]);
        }
        return ans;
    }
};