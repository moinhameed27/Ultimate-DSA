// Leetcode : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
/* Store the frequency of all words in a map and check for the unique words */
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        int m = s1.size(), n = s2.size();
        string str;
        // Store the frequency of all words from s1
        for (int i = 0; i < m; i++)
        {
            int j = i;
            while (j < m && s1[j] != ' ')
                j++;
            str = s1.substr(i, j - i);
            i = j;
            mp[str]++;
        }

        // Store the frequency of all words from s2
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && s2[j] != ' ')
                j++;
            str = s2.substr(i, j - i);
            i = j;
            mp[str]++;
        }

        // Check for the unique words
        for (auto it : mp)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};

// Way - II (StringStream)
/* StringStream divides the string into chunks of strings based on the spaces between them. */
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        stringstream ss1(s1), ss2(s2);
        string word;
        while (ss1 >> word)
            mp[word]++;

        while (ss2 >> word)
            mp[word]++;

        for (auto it : mp)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
    public String[] uncommonFromSentences(String A, String B)
    {
        Map<String, Integer> map = new HashMap<>();
        List<String> ans = new ArrayList<>();
        String[] s1 = A.split(" ");
        String[] s2 = B.split(" ");
        for (String s : s1)
            map.put(s, map.getOrDefault(s, 0) + 1);

        for (String s : s2)
            map.put(s, map.getOrDefault(s, 0) + 1);

        for (Map.Entry<String, Integer> entry : map.entrySet())
        {
            if (entry.getValue() == 1)
                ans.add(entry.getKey());
        }
        return ans.toArray(new String[ans.size()]);
    }
}

// Way - II (StringTokenizer)
class Solution
{
    public String[] uncommonFromSentences(String A, String B)
    {
        Map<String, Integer> map = new HashMap<>();
        List<String> ans = new ArrayList<>();
        StringTokenizer st1 = new StringTokenizer(A);
        StringTokenizer st2 = new StringTokenizer(B);
        while (st1.hasMoreTokens())
            map.put(st1.nextToken(), map.getOrDefault(st1.nextToken(), 0) + 1);

        while (st2.hasMoreTokens())
            map.put(st2.nextToken(), map.getOrDefault(st2.nextToken(), 0) + 1);
            
        for (Map.Entry<String, Integer> entry : map.entrySet())
        {
            if (entry.getValue() == 1)
                ans.add(entry.getKey());
        }
        return ans.toArray(new String[ans.size()]);
    }
}