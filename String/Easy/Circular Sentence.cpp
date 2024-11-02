// Leetcode : https://leetcode.com/problems/circular-sentence/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int n = sentence.size();
        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        }
        return sentence[0] == sentence[n - 1];
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public boolean isCircularSentence(String sentence)
    {
        int n = sentence.length();
        for (int i = 0; i < n; i++)
        {
            if (sentence.charAt(i) == ' ' && sentence.charAt(i - 1) != sentence.charAt(i + 1))
                return false;
        }
        return sentence.charAt(0) == sentence.charAt(n - 1);
    }
}