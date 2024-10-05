// Leetcode : https://leetcode.com/problems/permutation-in-string/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        // If s1 is greater than s2, then s1 can't be a substring of s2
        if (m > n)
            return false;
        // Frequency of characters in s1 and s2
        vector<int> freq1(26, 0), freq2(26, 0);
        // Count frequency of characters in s1
        for (char ch : s1)
            freq1[ch - 'a']++;

        // Check whether s1 is a permutation of s2 by sliding window in s2
        int i = 0, j = 0;
        while (j < n)
        {
            freq2[s2[j] - 'a']++;
            // If window size is equal to s1, then check whether frequency of characters in s1 and s2 are same
            if (j - i + 1 == m)
            {
                if (freq1 == freq2)
                    return true;
                // Slide the window from left side
                freq2[s2[i] - 'a']--;
                i++;
            }
            j++;
        }
        return false;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    public boolean checkInclusion(String s1, String s2)
    {
        int m = s1.length(), n = s2.length();
        // If s1 is greater than s2, then s1 can't be a substring of s2
        if (m > n)
            return false;
        // Frequency of characters in s1 and s2
        int[] freq1 = new int[26], freq2 = new int[26];
        // Count frequency of characters in s1
        for (char ch : s1.toCharArray())
            freq1[ch - 'a']++;

        // Check whether s1 is a permutation of s2 by sliding window in s2
        int i = 0, j = 0;
        while (j < n)
        {
            freq2[s2.charAt(j) - 'a']++;
            // If window size is equal to s1, then check whether frequency of characters in s1 and s2 are same
            if (j - i + 1 == m)
            {
                if (Arrays.equals(freq1, freq2))
                    return true;
                // Slide the window from left side
                freq2[s2.charAt(i) - 'a']--;
                i++;
            }
            j++;
        }
        return false;
    }
}