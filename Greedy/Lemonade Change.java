// Leetcode : https://leetcode.com/problems/lemonade-change/description/

// [C++]---------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fiveCount = 0, tenCount = 0;
        for (int bill : bills)
        {
            if (bill == 5)
                fiveCount++;
            else if (bill == 10)
            {
                tenCount++;
                if (fiveCount > 0)
                    fiveCount--;
                else
                    return false;
            }
            else
            {
                if (tenCount > 0 && fiveCount > 0)
                    tenCount--, fiveCount--;
                else if (fiveCount >= 3)
                    fiveCount -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

// [Java]---------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public boolean lemonadeChange(int[] bills)
    {
        int fiveCount = 0, tenCount = 0;
        for (int bill : bills)
        {
            if (bill == 5)
                fiveCount++;
            else if (bill == 10)
            {
                tenCount++;
                if (fiveCount > 0)
                    fiveCount--;
                else
                    return false;
            }
            else
            {
                if (tenCount > 0 && fiveCount > 0)
                {
                    tenCount--;
                    fiveCount--;
                }
                else if (fiveCount >= 3)
                    fiveCount -= 3;
                else
                    return false;
            }
        }
        return true;
    }
}