// LeetCode : https://leetcode.com/problems/number-of-senior-citizens

// Way - I (Brute Force [Built-In (stoi)])
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int age, count = 0;
        for (string i : details)
        {
            age = stoi(i.substr(11, 2));
            // age = (s[11] - '0') * 10 + (s[12] - '0');
            if (age > 60)
                count++;
        }
        return count;
    }
};

// Way - II
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int count = 0;
        for (string info : details)
        {
            char tens = info[11];
            char ones = info[12];
            if (tens > '6' || (tens == '6' && ones > '0'))
                count++;
        }
        return count;
    }
};
