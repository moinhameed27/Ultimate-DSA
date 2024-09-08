// Leetcode : https://leetcode.com/problems/jump-game/description/

// GFG : https://www.geeksforgeeks.org/problems/jump-game/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Simple Greedy)
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // If path is exhausted and we can't go further
            if (i > maxIndex)
                return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};

// Way - II (DP + Memoization)
class Solution
{
public:
    int t[10001];
    bool solve(vector<int> &nums, int n, int idx)
    {
        // If we reach the end
        if (idx == n - 1)
            return true;

        if (t[idx] != -1)
            return t[idx];

        // Check for all posibilites between range [1, nums[idx]]
        for (int i = 1; i <= nums[idx]; i++)
        {
            if (solve(nums, n, idx + i))
                return t[idx] = true;
        }

        return t[idx] = false;
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, n, 0);
    }
};

// Way - III (Greedy II)
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int current = 0, farthest = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, nums[i] + i);
            if (current == i)
                current = farthest;
        }
        return (current >= n - 1) ? true : false;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Simple Greedy)
class Solution
{
    public boolean canJump(int[] nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (i > maxIndex)
                return false;
            maxIndex = Math.max(maxIndex, i + nums[i]);
        }
        return true;
    }
}

// Way - II (DP + Memoization)
class Solution
{
    int t[] = new int[10001];
    public boolean solve(int[] nums, int n, int idx)
    {
        if (idx == n - 1)
            return true;

        if (t[idx] != -1)
            return t[idx] == 1;

        for (int i = 1; i <= nums[idx]; i++)
        {
            if (solve(nums, n, idx + i))
            {
                t[idx] = 1;
                return true;
            }
        }

        t[idx] = 0;
        return false;
    }
    public boolean canJump(int[] nums)
    {
        int n = nums.length;
        Arrays.fill(t, -1);
        return solve(nums, n, 0);
    }
}

// Way - III (Greedy II)
class Solution
{
    public boolean canJump(int[] nums)
    {
        int current = 0, farthest = 0, n = nums.length;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = Math.max(farthest, nums[i] + i);
            if (current == i)
                current = farthest;
        }
        return current >= n - 1;
    }
}