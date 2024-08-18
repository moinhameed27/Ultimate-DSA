// Leetcode : https://leetcode.com/problems/ugly-number/description/

/*
Ugly Number II
Problem : https://leetcode.com/problems/ugly-number-ii/description/
Solution : https://github.com/moinhameed27/Ultimate-DSA/blob/main/DP/Ugly%20Number%20II.cpp
*/

// [C++]----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
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
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public
    boolean isUgly(int n)
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