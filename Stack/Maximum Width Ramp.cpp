// Leetcode :

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n^2) time and O(1) space
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        int ramp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] <= nums[j])
                    ramp = max(ramp, j - i);
            }
        }
        return ramp;
    }
};

// Way - II (Stack) : O(n) time and O(n) space
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || nums[i] < nums[st.top()])
                st.push(i);
        }
        int maxWidth = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            while (!st.empty() && nums[st.top()] <= nums[j])
            {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n^2) time and O(1) space
class Solution
{
    public int maxWidthRamp(int[] nums)
    {
        int n = nums.length;
        int ramp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] <= nums[j])
                    ramp = Math.max(ramp, j - i);
            }
        }
        return ramp;
    }
}

// Way - II (Stack) : O(n) time and O(n) space
class Solution
{
    public int maxWidthRamp(int[] nums)
    {
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++)
        {
            if (st.isEmpty() || nums[i] < nums[st.peek()])
                st.push(i);
        }
        int maxWidth = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            while (!st.isEmpty() && nums[st.peek()] <= nums[j])
            {
                maxWidth = Math.max(maxWidth, j - st.peek());
                st.pop();
            }
        }

        return maxWidth;
    }
}