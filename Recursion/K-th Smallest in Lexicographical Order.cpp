// Leetcode : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting with String Comparison]) : O(nlogn) time and O(n) space [TLE]
class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        vector<int> numbers(n);
        // Fill the array with numbers starting from 1 till n
        iota(numbers.begin(), numbers.end(), 1);

        // Sort in Lexicographical order
        sort(numbers.begin(), numbers.end(), [](int a, int b)
             { return to_string(a) < to_string(b); });

        return numbers[k - 1];
    }
};

// Way - II (Recursion [DFS]) : O(n) time and O(1) space [TLE]
class Solution
{
    bool solve(long long curr, int n, int k, int &count, int &ans)
    {
        if (curr > n)
            return false;
        // Increment the count and check if it is equal to k
        count++;
        if (count == k)
        {
            ans = curr;
            return true;
        }

        // Try to append 0 to 9 to the current number
        for (int append = 0; append <= 9; append++)
        {
            long long newNumber = (curr * 10) + append;
            if (newNumber > n)
                return false;
            if (solve(newNumber, n, k, count, ans))
                return true;
        }
        return false;
    }

public:
    int findKthNumber(int n, int k)
    {
        int count = 0, ans = -1;
        for (long long i = 1; i <= 9; i++)
        {
            if (solve(i, n, k, count, ans))
                break;
        }

        return ans;
    }
};

// Way - III (Skip unneccessary numbers) : O(logn) time and O(1) space
class Solution
{
    int countNumbers(long curr, long next, int n)
    {
        int count = 0;
        // Count the number of numbers between curr and next
        while (curr <= n)
        {
            count += next - curr;
            curr *= 10; // Move to the next level
            next *= 10; 
            // To keep the next number in the range of 1 to n
            next = min(next, long(n) + 1);
        }
        return count;
    }

public:
    int findKthNumber(int n, int k)
    {
        int curr = 1;
        k--;    // 0-based Indexing
        while (k > 0)
        {
            // Count the number of numbers between curr and curr + 1
            int count = countNumbers(curr, curr + 1, n);
            // If the count is less than k, then move to the next number
            if (count <= k)
            {
                curr++;
                k -= count; // Skip the count numbers
            }
            // Else move to the next level in the lexicographical order
            else
            {
                k--;    // Skip the current number
                curr *= 10; // Move to the next level
            }
        }
        return curr;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting with String Comparison]) : O(nlogn) time and O(n) space [TLE]
class Solution 
{
    public int findKthNumber(int n, int k) 
    {
        List<Integer> numbers = new ArrayList<>();
        // Fill the array with numbers starting from 1 till n
        for (int i = 1; i <= n; i++)
            numbers.add(i);
        
        // Sort in Lexicographical order
        Collections.sort(numbers, (a, b) -> String.valueOf(a).compareTo(String.valueOf(b)));
        
        return numbers.get(k - 1);
    }
}

// Way - II (Recursion [DFS]) : O(n) time and O(1) space [TLE]
class Solution 
{
    private boolean solve(long curr, int n, int k, int[] count, int[] ans)
    {
        if (curr > n)
            return false;
        // Increment the count and check if it is equal to k
        count[0]++;
        if (count[0] == k)
        {
            ans[0] = (int)curr;
            return true;
        }
        
        // Try to append 0 to 9 to the current number
        for (int append = 0; append <= 9; append++)
        {
            long newNumber = (curr * 10) + append;
            if (newNumber > n)
                return false;
            if (solve(newNumber, n, k, count, ans))
                return true;
        }
        return false;
    }
    
    public int findKthNumber(int n, int k) 
    {
        int[] count = new int[1], ans = new int[1];
        for (long i = 1; i <= 9; i++)
        {
            if (solve(i, n, k, count, ans))
                break;
        }
        
        return ans[0];
    }
}

// Way - III (Skip unneccessary numbers) : O(logn) time and O(1) space
class Solution 
{
    private int countNumbers(long curr, long next, int n)
    {
        int count = 0;
        // Count the number of numbers between curr and next
        while (curr <= n)
        {
            count += next - curr;
            curr *= 10; // Move to the next level
            next *= 10; 
            // To keep the next number in the range of 1 to n
            next = Math.min(next, n + 1);
        }
        return count;
    }
    
    public int findKthNumber(int n, int k) 
    {
        int curr = 1;
        k--;    // 0-based Indexing
        while (k > 0)
        {
            // Count the number of numbers between curr and curr + 1
            int count = countNumbers(curr, curr + 1, n);
            // If the count is less than k, then move to the next number
            if (count <= k)
            {
                curr++;
                k -= count; // Skip the count numbers
            }
            // Else move to the next level in the lexicographical order
            else
            {
                k--;    // Skip the current number
                curr *= 10; // Move to the next level
            }
        }
        return curr;
    }
}
