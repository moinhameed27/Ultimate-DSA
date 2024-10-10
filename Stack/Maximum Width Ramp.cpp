// Leetcode : https://leetcode.com/problems/maximum-width-ramp/

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

// Way - II (Better Brute Force) : O(n^2) time and O(1) space
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        int maxWidth = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] <= nums[j])
                {
                    maxWidth = max(maxWidth, j - i);
                    break;
                }
            }
        }
        return maxWidth;
    }
};

// Way - III (Two Pointers) : O(n) time and O(n) space
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        int maxWidth = 0;

        // Storing the maximum element from right side for each element
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], nums[i]);

        int i = 0, j = 0;   // i for nums and j for rightMax
        while (j < n)
        {
            // nums[i] > rightMax[j] means the current element is not a valid ramp
            while (i < j && nums[i] > rightMax[j])
                i++;

            maxWidth = max(maxWidth, j - i);
            j++;
        }
        return maxWidth;
    }
};

// Way - IV (Stack) : O(n) time and O(n) space
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        // Store index of elements and maintain the stack in increasing order of elements (Monotonic Stack)
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || nums[i] < nums[st.top()])
                st.push(i);
        }
        int maxWidth = 0;
        // Traverse the array in reverse order and pop the elements from stack until the current element is greater than the top of stack
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

// Way - II (Better Brute Force) : O(n^2) time and O(1) space
class Solution
{
    public int maxWidthRamp(int[] nums)
    {
        int n = nums.length;
        int maxWidth = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] <= nums[j])
                {
                    maxWidth = Math.max(maxWidth, j - i);
                    break;
                }
            }
        }
        return maxWidth;
    }
}

// Way - III (Two Pointers) : O(n) time and O(n) space
class Solution
{
    public int maxWidthRamp(int[] nums)
    {
        int n = nums.length;
        int maxWidth = 0;

        // Storing the maximum element from right side for each element
        int[] rightMax = new int[n];
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = Math.max(rightMax[i + 1], nums[i]);

        int i = 0, j = 0;   // i for nums and j for rightMax
        while (j < n)
        {
            // nums[i] > rightMax[j] means the current element is not a valid ramp
            while (i < j && nums[i] > rightMax[j])
                i++;

            maxWidth = Math.max(maxWidth, j - i);
            j++;
        }
        return maxWidth;
    }
}

// Way - IV (Stack) : O(n) time and O(n) space
class Solution
{
    public int maxWidthRamp(int[] nums)
    {
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        // Store index of elements and maintain the stack in increasing order of elements (Monotonic Stack)
        for (int i = 0; i < n; i++)
        {
            if (st.isEmpty() || nums[i] < nums[st.peek()])
                st.push(i);
        }
        int maxWidth = 0;
        // Traverse the array in reverse order and pop the elements from stack until the current element is greater than the top of stack
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