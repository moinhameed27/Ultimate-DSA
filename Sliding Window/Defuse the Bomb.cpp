// Leetcode : https://leetcode.com/problems/defuse-the-bomb/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n * k) time and O(n) space (for Answer)
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;

        for (int i = 0; i < n; i++)
        {
            int j = i, l = abs(k);
            // If k is positive, add next k elements
            if (k > 0)
            {
                while (l--)
                {
                    j = (j + 1) % n;
                    ans[i] += code[j];
                }
            }
            // If k is negative, add previous k elements
            else
            {
                while (l--)
                {
                    j = (j == 0) ? n - 1 : j - 1;
                    ans[i] += code[j];
                }
            }
        }
        return ans;
    }
};

// Way - II (Sliding Window + Prefix Sum) : O(n) time and O(n) space (for Answer)
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;

        int i, j;
        // if k is positive, start with first k elements after 0th index
        if (k > 0)
            i = 1, j = k;
        // if k is negative, start with last k elements before 0th index
        else
            i = n + k, j = n - 1;

        int sum = accumulate(code.begin() + i, code.begin() + j + 1, 0);

        for (int idx = 0; idx < n; idx++)
        {
            ans[idx] = sum;
            sum -= code[i]; // remove ith element from sum
            i = (i + 1) % n;
            j = (j + 1) % n;
            sum += code[j]; // add jth element to sum
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n * k) time and O(n) space (for Answer)
class Solution
{
    public int[] decrypt(int[] code, int k)
    {
        int n = code.length;
        int[] ans = new int[n];
        if (k == 0)
            return ans;

        for (int i = 0; i < n; i++)
        {
            int j = i, l = Math.abs(k);
            if (k > 0)
            {
                while (l-- > 0)
                {
                    j = (j + 1) % n;
                    ans[i] += code[j];
                }
            }
            else
            {
                while (l-- > 0)
                {
                    j = (j == 0) ? n - 1 : j - 1;
                    ans[i] += code[j];
                }
            }
        }
        return ans;
    }
}

// Way - II (Sliding Window + Prefix Sum) : O(n) time and O(n) space (for Answer)
class Solution
{
    public int[] decrypt(int[] code, int k)
    {
        int n = code.length;
        int[] ans = new int[n];
        if (k == 0)
            return ans;

        int i, j;
        if (k > 0)
            i = 1;
        else
            i = n + k;

        j = (i + Math.abs(k) - 1) % n;
        int sum = 0;
        for (int idx = i; idx <= j; idx++)
            sum += code[idx];

        for (int idx = 0; idx < n; idx++)
        {
            ans[idx] = sum;
            sum -= code[i];
            i = (i + 1) % n;
            j = (j + 1) % n;
            sum += code[j];
        }
        return ans;
    }
}