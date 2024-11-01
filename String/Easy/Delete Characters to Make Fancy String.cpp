// Leetcode : https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    string makeFancyString(string s)
    {
        int n = s.size();
        if (n < 3)
            return s;
        string ans = "";
        char ch1 = s[0], ch2 = s[1], ch3;
        ans += ch1;
        ans += ch2;
        for (int i = 2; i < n; i++)
        {
            ch3 = s[i];
            if (!(ch1 == ch2 && ch2 == ch3))
                ans += ch3;
            ch1 = ch2;
            ch2 = ch3;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public String makeFancyString(String s)
    {
        int n = s.length();
        if (n < 3)
            return s;
        StringBuilder ans = new StringBuilder();
        char ch1 = s.charAt(0), ch2 = s.charAt(1), ch3;
        ans.append(ch1);
        ans.append(ch2);
        for (int i = 2; i < n; i++)
        {
            ch3 = s.charAt(i);
            if (!(ch1 == ch2 && ch2 == ch3))
                ans.append(ch3);
            ch1 = ch2;
            ch2 = ch3;
        }
        return ans.toString();
    }
}
