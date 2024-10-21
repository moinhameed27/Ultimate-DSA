// Leetcode : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    void solve(string &s, unordered_set<string> substrings, int n, int idx, int currCount, int &maxCount)
    {
        // If current count + maximum number of substrings that can be formed from remaining string is less than or equal to maxCount, then return
        if (currCount + (n - idx) <= maxCount)
            return;

        // If we have reached the end of the string, update maxCount and return
        if (idx == n)
        {
            maxCount = max(maxCount, currCount);
            return;
        }

        for (int j = idx; j < n; j++)
        {
            string subst = s.substr(idx, j - idx + 1);
            // If substring is not present in the set, add it, explore with it and remove it
            if (substrings.find(subst) == substrings.end())
            {
                substrings.insert(subst);
                solve(s, substrings, n, j + 1, currCount + 1, maxCount);
                substrings.erase(subst);
            }
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        int n = s.size();
        unordered_set<string> substrings;
        int currCount = 0, maxCount = 0;
        solve(s, substrings, n, 0, currCount, maxCount);
        return maxCount;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    void solve(String s, Set<String> substrings, int idx, int currCount, int[] maxCount)
    {
        // If current count + maximum number of substrings that can be formed from remaining string is less than or equal to maxCount, then return
        if (currCount + (s.length() - idx) <= maxCount[0])
            return;

        // If we have reached the end of the string, update maxCount and return
        if (idx == s.length())
        {
            maxCount[0] = Math.max(maxCount[0], currCount);
            return;
        }

        for (int j = idx; j < s.length(); j++)
        {
            String subst = s.substring(idx, j + 1);
            // If substring is not present in the set, add it, explore with it and remove it
            if (!substrings.contains(subst))
            {
                substrings.add(subst);
                solve(s, substrings, j + 1, currCount + 1, maxCount);
                substrings.remove(subst);
            }
        }
    }

    public int maxUniqueSplit(String s)
    {
        Set<String> substrings = new HashSet<>();
        int[] maxCount = new int[1];
        solve(s, substrings, 0, 0, maxCount);
        return maxCount[0];
    }
}