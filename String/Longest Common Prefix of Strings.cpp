// GFG : https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

/* Get to the minimum string of array and check for it's characters in other strings */
class Solution
{
    bool findInAllStrings(vector<string> &arr, char ch, int idx)
    {
        for (string &str : arr)
        {
            // If the character is not present in any string or the character is not at the same index
            if (idx >= str.size() || str[idx] != ch)
                return false;
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string> arr)
    {
        if (arr.empty())
            return "";

        string commonStr = "", minStr = "";
        int minStrSize = INT_MAX;
        // Find the minimum string
        for (string &str : arr)
        {
            if (str.size() < minStrSize)
            {
                minStrSize = str.size();
                minStr = str;
            }
        }

        for (int i = 0; i < minStrSize; i++)
        {
            if (findInAllStrings(arr, minStr[i], i))
                commonStr += minStr[i];
            else
                break;
        }
        // If no common prefix found, return -1
        return commonStr == "" ? "-1" : commonStr;
    }
};