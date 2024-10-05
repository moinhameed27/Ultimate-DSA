// Leetcode : https://leetcode.com/problems/permutation-in-string/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n! * m) time and O(1) space
/* Find all the permutations of s1 and check if any is present in s2. */
class Solution
{
    int m;
    bool ans;
    // Find all permutations
    void solve(int idx, string &s1, string &s2)
    {
        // If all permutations are found, check if any is present in s2
        if (idx == m)
        {
            if (s2.find(s1) != string::npos)
                ans = true;
            return;
        }
        // Exploring for more permutations
        for (int i = idx; i < m; i++)
        {
            swap(s1[i], s1[idx]);
            solve(idx + 1, s1, s2);
            swap(s1[i], s1[idx]);
            if (ans)
                return;
        }
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        m = s1.size();
        int n = s2.size();
        // If s1 is greater than s2, then s1 can't be a substring of s2
        if (m > n)
            return false;
        ans = false;
        solve(0, s1, s2);
        return ans;
    }
};

// Way - II (Sorting and Comparing) : O(nlogn * (m - n)) time and O(m) space
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        sort(s1.begin(), s1.end()); // Sort s1
        for (int i = 0; i <= n - m; i++)
        {
            // Sort substring of s2 of length m
            string perm = s2.substr(i, m);
            sort(perm.begin(), perm.end());
            // If sorted s1 and sorted perm are same, then s1 is a permutation of s2
            if (s1 == perm)
                return true;
        }
        return false;   // s1 is not a permutation of s2
    }
};

// Way - III (Sliding Window) : O(n) time and O(26 + 26) space
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
// Way - I (Brute Force) : O(n! * m) time and O(1) space
/* Find all the permutations of s1 and check if any is present in s2. */
class Solution
{
    boolean ans;
    int m;
    // Find all permutations
    void solve(int idx, char[] s1, String s2)
    {
        // If all permutations are found, check if any is present in s2
        if (idx == m)
        {
            if (s2.indexOf(new String(s1)) != -1)
                ans = true;
            return;
        }
        // Exploring for more permutations
        for (int i = idx; i < m; i++)
        {
            char temp = s1[i];
            s1[i] = s1[idx];
            s1[idx] = temp;
            solve(idx + 1, s1, s2);
            temp = s1[i];
            s1[i] = s1[idx];
            s1[idx] = temp;
            if (ans)
                return;
        }
    }

    public boolean checkInclusion(String s1, String s2)
    {
        m = s1.length();
        int n = s2.length();
        // If s1 is greater than s2, then s1 can't be a substring of s2
        if (m > n)
            return false;
        ans = false;
        solve(0, s1.toCharArray(), s2);
        return ans;
    }
}

// Way - II (Sorting and Comparing) : O(nlogn * (m - n)) time and O(m) space
class Solution
{
    public boolean checkInclusion(String s1, String s2)
    {
        int m = s1.length(), n = s2.length();
        char[] s1Arr = s1.toCharArray();
        Arrays.sort(s1Arr); // Sort s1
        for (int i = 0; i <= n - m; i++)
        {
            // Sort substring of s2 of length m
            char[] perm = s2.substring(i, i + m).toCharArray();
            Arrays.sort(perm);
            // If sorted s1 and sorted perm are same, then s1 is a permutation of s2
            if (Arrays.equals(s1Arr, perm))
                return true;
        }
        return false;   // s1 is not a permutation of s2
    }
}

// Way - III (Sliding Window) : O(n) time and O(26 + 26) space
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