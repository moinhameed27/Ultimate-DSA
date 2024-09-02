// Leetcode : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE]
class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        for (int i = 0; i < n; i = (i + 1) % n)
        {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 0;
    }
};

// Way - II (Remainder)
class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        // Sum of Array
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;
        for (int i = 0; i < n; i++)
        {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 0;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE]
class Solution
{
    public int chalkReplacer(int[] chalk, int k)
    {
        int n = chalk.length;
        for (int i = 0; i < n; i = (i + 1) % n)
        {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 0;
    }
}

// Way - II (Remainder)
class Solution
{
    public int chalkReplacer(int[] chalk, int k)
    {
        int n = chalk.length;
        // Sum of Array
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += chalk[i];
        k %= sum;
        for (int i = 0; i < n; i++)
        {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 0;
    }
}