// Leetcode : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.size();
        vector<int> freq(26, 0);
        // Store frequencies of each character
        for (char ch : word)
            freq[ch - 'a']++;
        // Sort them in descending order
        sort(freq.begin(), freq.end(), greater<>());

        int pushes = 0;
        // Now we will press the characters in the order of their frequencies
        for (int i = 0; i < 26; i++)
            pushes += freq[i] * (i / 8 + 1);
        return pushes;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public
    int minimumPushes(String word)
    {
        int n = word.length();
        List<Integer> freq = new ArrayList<>(Collections.nCopies(26, 0));

        // Store frequencies of each character
        for (char ch : word.toCharArray())
            freq.set(ch - 'a', freq.get(ch - 'a') + 1);

        // Sort them in descending order
        Collections.sort(freq, Collections.reverseOrder());

        int pushes = 0;

        // Now we will press the characters in the order of their frequencies
        for (int i = 0; i < 26; i++)
            pushes += freq.get(i) * (i / 8 + 1);

        return pushes;
    }
}
