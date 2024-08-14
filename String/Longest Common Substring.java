// GFG : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

// C++---------------------------------------------------------------------------------------------------------------------
/* Find all substrings in one string, if it's found in the other one, count it's size */
class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int m = str1.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                string str = str1.substr(i, j - i + 1);
                int s = str.size();
                if (str2.find(str) != string::npos)
                    ans = max(ans, s);
            }
        }
        return ans;
    }
};

// Java---------------------------------------------------------------------------------------------------------------------
class Solution
{
public
    int longestCommonSubstr(String str1, String str2)
    {
        int m = str1.length();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                String str = str1.substring(i, j + 1);
                if (str2.contains(str))
                    ans = Math.max(ans, str.length());
            }
        }
        return ans;
    }
}