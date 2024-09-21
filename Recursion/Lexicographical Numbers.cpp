// Leetcode : https://leetcode.com/problems/lexicographical-numbers/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting with String Comparison]) : O(nlogn) time and O(n) space
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> numbers(n);
        // Fill the array with numbers starting from 1 till n
        iota(numbers.begin(), numbers.end(), 1);

        // Sort in Lexicographical order
        sort(numbers.begin(), numbers.end(), [](int a, int b)
             { return to_string(a) < to_string(b); });

        return numbers;
    }
};

// Way - II (Recursion [DFS]) : O(n) time and O(n) space
class Solution
{
    void solve(int curr, int n, vector<int> &numbers)
    {
        if (curr > n)
            return;
        numbers.push_back(curr);

        // Append 0 to 9 to the current number
        for (int append = 0; append <= 9; append++)
        {
            int newNumber = (curr * 10) + append;
            if (newNumber > n)
                return;
            // Recursively call for the new number
            solve(newNumber, n, numbers);
        }
    }

public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> numbers;

        // Start from 1 to 9
        for (int i = 1; i <= 9; i++)
            solve(i, n, numbers);

        return numbers;
    }
};

// Way - III (Iterative) : O(n) time and O(n) space
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> numbers;
        int curr = 1;

        for (int i = 0; i < n; i++)
        {
            numbers.push_back(curr);
            if (curr * 10 <= n)
                curr *= 10;
            else
            {
                if (curr >= n)
                    curr /= 10;

                curr++;

                while (curr % 10 == 0)
                    curr /= 10;
            }
        }
        return numbers;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting with String Comparison]) : O(nlogn) time and O(n) space
class Solution
{
    public List<Integer> lexicalOrder(int n)
    {
        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            numbers.add(i);

        Collections.sort(numbers, (a, b) -> String.valueOf(a).compareTo(String.valueOf(b)));
        return numbers;
    }
}

// Way - II (Recursion [DFS]) : O(n) time and O(n) space
class Solution
{
    private void solve(int curr, int n, List<Integer> numbers)
    {
        if (curr > n)
            return;
        numbers.add(curr);

        for (int append = 0; append <= 9; append++)
        {
            int newNumber = (curr * 10) + append;
            if (newNumber > n)
                return;
            solve(newNumber, n, numbers);
        }
    }

    public List<Integer> lexicalOrder(int n)
    {
        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= 9; i++)
            solve(i, n, numbers);

        return numbers;
    }
}

// Way - III (Iterative) : O(n) time and O(n) space
class Solution
{
    public List<Integer> lexicalOrder(int n)
    {
        List<Integer> numbers = new ArrayList<>();
        int curr = 1;

        for (int i = 0; i < n; i++)
        {
            numbers.add(curr);
            if (curr * 10 <= n)
                curr *= 10;
            else
            {
                if (curr >= n)
                    curr /= 10;

                curr++;

                while (curr % 10 == 0)
                    curr /= 10;
            }
        }
        return numbers;
    }
}