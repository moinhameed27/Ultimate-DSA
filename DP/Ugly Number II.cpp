// Leetcode : https://leetcode.com/problems/ugly-number-ii/description/

/* 
Ugly Number I
Problem : https://leetcode.com/problems/ugly-number/description/
Solution : https://github.com/moinhameed27/Ultimate-DSA/blob/main/Maths/Ugly%20Number.cpp
*/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE] : O(nlogn) time and O(1) space
class Solution
{
    bool isUgly(int n)
    {
        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return n == 1;
    }

public:
    int nthUglyNumber(int n)
    {
        int num = 0, count = 0;
        while (count < n)
        {
            num++;
            if (isUgly(num))
                count++;
        }
        return num;
    }
};

// Way - II (DP) [MLE] : O(n) time and O(n) space
class Solution
{
public:
    unordered_map<int, bool> mp;
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        if (mp.find(n) != mp.end())
            return mp[n];

        if (n % 2 == 0 && isUgly(n / 2))
            return mp[n] = true;
        else if (n % 3 == 0 && isUgly(n / 3))
            return mp[n] = true;
        else if (n % 5 == 0 && isUgly(n / 5))
            return mp[n] = true;

        return mp[n] = false;
    }
    int nthUglyNumber(int n)
    {
        mp.clear();
        int num = 1;
        while (n > 0)
        {
            if (isUgly(num))
                n--;
            num++;
        }
        return num - 1;
    }
};

// Way - III (DP) : O(n) time and O(n) space
/* Using the fact that ugly numbers multiplying with ugly numbers will surely produce ugly Numbers */
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> uglyNumbers(n + 1); // ith ugly number
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        uglyNumbers[1] = 1;     // First ugly number
        for (int i = 2; i <= n; i++)
        {
            int multipleOfTwo = uglyNumbers[i2] * 2;
            int multipleOfThree = uglyNumbers[i3] * 3;
            int multipleOfFive = uglyNumbers[i5] * 5;

            // Whichever is the minimum will be the next ugly number
            uglyNumbers[i] = min({multipleOfTwo, multipleOfThree, multipleOfFive});

            if (uglyNumbers[i] == multipleOfTwo)
                i2++;
            if (uglyNumbers[i] == multipleOfThree)
                i3++;
            if (uglyNumbers[i] == multipleOfFive)
                i5++;
        }
        return uglyNumbers[n];
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) [TLE] : O(nlogn) time and O(1) space
class Solution
{
    public int nthUglyNumber(int n)
    {
        int num = 0, count = 0;
        while (count < n)
        {
            num++;
            if (isUgly(num))
                count++;
        }
        return num;
    }

    public boolean isUgly(int n)
    {
        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return n == 1;
    }
}

// Way - II (DP) [MLE] : O(n) time and O(n) space
class Solution 
{
    private Map<Integer, Boolean> mp = new HashMap<>();

    public boolean isUgly(int n) 
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        if (mp.containsKey(n))
            return mp.get(n);

        if (n % 2 == 0 && isUgly(n / 2))
        {
            mp.put(n, true);
            return true;
        }
        else if (n % 3 == 0 && isUgly(n / 3))
        {
            mp.put(n, true);
            return true;
        }
        else if (n % 5 == 0 && isUgly(n / 5))
        {
            mp.put(n, true);
            return true;
        }

        mp.put(n, false);
        return false;
    }

    public int nthUglyNumber(int n) 
    {
        int num = 1;
        while (n > 0) 
        {
            if (isUgly(num))
                n--;
            num++;
        }
        return num - 1;
    }
}

// Way - III (DP) : O(n) time and O(n) space
class Solution
{
    public int nthUglyNumber(int n)
    {
        int[] uglyNumbers = new int[n + 1]; // ith ugly number
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        uglyNumbers[1] = 1;     // First ugly number
        for (int i = 2; i <= n; i++)
        {
            int multipleOfTwo = uglyNumbers[i2] * 2;
            int multipleOfThree = uglyNumbers[i3] * 3;
            int multipleOfFive = uglyNumbers[i5] * 5;

            // Whichever is the minimum will be the next ugly number
            uglyNumbers[i] = Math.min(Math.min(multipleOfTwo, multipleOfThree), multipleOfFive);

            if (uglyNumbers[i] == multipleOfTwo)
                i2++;
            if (uglyNumbers[i] == multipleOfThree)
                i3++;
            if (uglyNumbers[i] == multipleOfFive)
                i5++;
        }
        return uglyNumbers[n];
    }
}