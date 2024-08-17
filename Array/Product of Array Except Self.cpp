// Leetcode : https://leetcode.com/problems/product-of-array-except-self/description/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE] : O(n^2) time and O(1) space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                product *= nums[j];
            }
            ans[i] = product;
        }
        return ans;
    }
};

// Way - II (Using Division) : O(n) time and O(1) space
/*
1. Find the product of all elements and product of all elements except zero.
2. Also count the number of zeros.
3. If there are more than 1 zeros, then all elements will be zero.
4. If there is only one zero, then that zero will have answer productWithoutZero.
5. If there are no zeros, then ans[i] = product / nums[i].
*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int product = 1, productWithoutZero = 1, zerosCount = 0;
        for (int i : nums)
        {
            product *= i;
            if (i != 0)
                productWithoutZero *= i;
            else
                zerosCount++;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (zerosCount > 1)
                    ans[i] = 0;
                else
                    ans[i] = productWithoutZero;
            }
            else
                ans[i] = product / nums[i];
        }
        return ans;
    }
};

// Way - III (Using Prefix and Suffix) : O(n) time and O(n) space
/*
1. Calculate prefix product of all elements.
2. Calculate suffix product of all elements.
3. ans[i] = prefix[i] * suffix[i].
*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        // Prefix product
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i - 1] * prefix[i - 1];
        // Suffix product
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = nums[i + 1] * suffix[i + 1];

        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i];

        return ans;
    }
};

// Way - IV (Using Prefix and Suffix) : O(n) time and O(1) space
/*
1. Use answer array as prefix array.
2. Calculate prefix product of all elements.
3. Calculate running suffix product of all elements.
*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        // Prefix product
        for (int i = 1; i < n; i++)
            ans[i] = nums[i - 1] * ans[i - 1];

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE] : O(n^2) time and O(1) space
class Solution
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                product *= nums[j];
            }
            ans[i] = product;
        }
        return ans;
    }
}

// Way - II (Using Division) : O(n) time and O(1) space
class Solution
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] ans = new int[n];
        int product = 1, productWithoutZero = 1, zerosCount = 0;
        for (int i : nums)
        {
            product *= i;
            if (i != 0)
                productWithoutZero *= i;
            else
                zerosCount++;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (zerosCount > 1)
                    ans[i] = 0;
                else
                    ans[i] = productWithoutZero;
            }
            else
                ans[i] = product / nums[i];
        }
        return ans;
    }
}

// Way - III (Using Prefix and Suffix) : O(n) time and O(n) space
class Solution
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] ans = new int[n];
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        prefix[0] = 1;
        suffix[n - 1] = 1;
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i - 1] * prefix[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = nums[i + 1] * suffix[i + 1];

        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i];

        return ans;
    }
}

// Way - IV (Using Prefix and Suffix) : O(n) time and O(1) space
class Solution
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] ans = new int[n];
        // Prefix product
        ans[0] = 1;
        for (int i = 1; i < n; i++)
            ans[i] = nums[i - 1] * ans[i - 1];

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
}