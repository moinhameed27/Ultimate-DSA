// Leetcode : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Set]) : O(n * m) time and O(26) space
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int ans = 0;
        unordered_set<char> st(allowed.begin(), allowed.end());

        for (string &str : words)
        {
            bool flag = true;
            for (char &ch : str)
            {
                if (st.find(ch) == st.end())
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};

// Way - II (Boolean Array) : O(n * m) time and O(26) space
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int ans = 0;
        vector<bool> isPresent(26, false);
        for (char ch : allowed)
            isPresent[ch - 'a'] = true;

        for (string &str : words)
        {
            bool flag = true;
            for (char &ch : str)
            {
                if (!isPresent[ch - 'a'])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};

// Way - III (Bitmask) : O(n * m) time and O(1) space
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int ans = 0, mask = 0;
        // Creating a mask : setting all the bits of allowed characters to 1
        // Left shift 1 by (ch - 'a') and OR with mask
        for (char ch : allowed)
            mask |= 1 << (ch - 'a');

        for (string &str : words)
        {
            bool flag = true;
            for (char &ch : str)
            {
                // Checking whether the bit is set or not
                // Right shift mask by (ch - 'a') and AND with 1
                if ((mask >> (ch - 'a') & 1) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Set]) : O(n * m) time and O(26) space
class Solution
{
    public int countConsistentStrings(String allowed, String[] words)
    {
        int ans = 0;
        Set<Character> st = new HashSet<>();
        for (char ch : allowed.toCharArray())
            st.add(ch);

        for (String str : words)
        {
            boolean flag = true;
            for (char ch : str.toCharArray())
            {
                if (!st.contains(ch))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
}

// Way - II (Boolean Array) : O(n * m) time and O(26) space
class Solution
{
    public int countConsistentStrings(String allowed, String[] words)
    {
        int ans = 0;
        boolean[] isPresent = new boolean[26];
        for (char ch : allowed.toCharArray())
            isPresent[ch - 'a'] = true;

        for (String str : words)
        {
            boolean flag = true;
            for (char ch : str.toCharArray())
            {
                if (!isPresent[ch - 'a'])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
}

// Way - III (Bitmask) : O(n * m) time and O(1) space
class Solution
{
    public int countConsistentStrings(String allowed, String[] words)
    {
        int ans = 0, mask = 0;
        for (char ch : allowed.toCharArray())
            mask |= 1 << (ch - 'a');

        for (String str : words)
        {
            boolean flag = true;
            for (char ch : str.toCharArray())
            {
                if ((mask >> (ch - 'a') & 1) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
}