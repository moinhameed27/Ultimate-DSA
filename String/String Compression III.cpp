// Leetcode : https://leetcode.com/problems/string-compression-iii/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    string compressedString(string word)
    {
        string ans = "";
        int n = word.size(), i = 0;

        while (i < n)
        {
            int count = 0;
            char ch = word[i];
            while (i < n && word[i] == ch && count < 9)
            {
                count++;
                i++;
            }
            ans += to_string(count) + ch;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public String compressedString(String word)
    {
        StringBuilder ans = new StringBuilder();
        int n = word.length(), i = 0;

        while (i < n)
        {
            int count = 0;
            char ch = word.charAt(i);
            while (i < n && word.charAt(i) == ch && count < 9)
            {
                count++;
                i++;
            }
            ans.append(count).append(ch);
        }
        return ans.toString();
    }
}