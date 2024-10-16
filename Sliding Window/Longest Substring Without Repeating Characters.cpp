// Leetcode : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [All Substrings]) : O(n ^ 2) time and O(n) space
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> st;
            // If character is already present in the set then break the loop, otherwise add it to the set and update the answer.
            for (int j = i; j < n; j++)
            {
                if (st.find(s[j]) != st.end())
                    break;
                st.insert(s[j]);
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

// Way - II (Sliding Window) : O(n) time and O(n) space
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char, int> freq;
        while (j < n)
        {
            freq[s[j]]++;
            // If frequency of character at j is greater than 1 then remove the character at i and increment i until no 
            // repeating character is present.
            while (freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [All Substrings]) : O(n ^ 2) time and O(n) space
class Solution
{
    public int lengthOfLongestSubstring(String s)
    {
        int n = s.length();
        int ans = 0;
        // If character is already present in the set then break the loop, otherwise add it to the set and update the answer.
        for (int i = 0; i < n; i++)
        {
            Set<Character> st = new HashSet<>();
            for (int j = i; j < n; j++)
            {
                if (st.contains(s.charAt(j)))
                    break;
                st.add(s.charAt(j));
                ans = Math.max(ans, j - i + 1);
            }
        }
        return ans;
    }
}

// Way - II (Sliding Window) : O(n) time and O(n) space
class Solution
{
    public int lengthOfLongestSubstring(String s)
    {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        Map<Character, Integer> freq = new HashMap<>();
        while (j < n)
        {
            freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0) + 1);
            // If frequency of character at j is greater than 1 then remove the character at i and increment i until no 
            // repeating character is present.
            while (freq.get(s.charAt(j)) > 1)
            {
                freq.put(s.charAt(i), freq.get(s.charAt(i)) - 1);
                i++;
            }
            ans = Math.max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
}