// Leetcode : https://leetcode.com/problems/rotate-string/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Rotate Function) : O(n^2) time and O(n) space
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            rotate(s, 1, n);
            if (s == goal)
                return true;
        }
        return false;
    }

    void rotate(string &s, int k, int n)
    {
        k %= n;
        string copy = s;
        for (int i = 0; i < n; i++)
        {
            s[i] = copy[(i + k) % n];
        }
    }
};

// Way - II (Erase and Append) : O(n^2) time and O(1) space
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int m = s.size(), n = goal.size();
        if (m != n)
            return false;

        for (int i = 0; i < m; i++)
        {
            if (s == goal)
                return true;

            char ch = s[0];
            s.erase(0, 1);
            s.push_back(ch);
        }
        return false;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Rotate Function) : O(n^2) time and O(n) space
class Solution
{
    public boolean rotateString(String s, String goal)
    {
        if (s.length() != goal.length())
            return false;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            s = rotate(s, 1, n);
            if (s.equals(goal))
                return true;
        }
        return false;
    }

    public String rotate(String s, int k, int n)
    {
        k %= n;
        char[] copy = s.toCharArray();
        for (int i = 0; i < n; i++)
        {
            s = s.substring(0, i) + copy[(i + k) % n];
        }
        return s;
    }
}

// Way - II (Erase and Append) : O(n^2) time and O(1) space
class Solution
{
    public boolean rotateString(String s, String goal)
    {
        int m = s.length(), n = goal.length();
        if (m != n)
            return false;

        for (int i = 0; i < m; i++)
        {
            if (s.equals(goal))
                return true;

            char ch = s.charAt(0);
            s = s.substring(1) + ch;
        }
        return false;
    }
}