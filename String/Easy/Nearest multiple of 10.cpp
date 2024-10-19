// GFG : https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    string roundToNearest(string str)
    {
        int n = str.size();
        int lastDigit = str[n - 1] - '0';
        int carry = (lastDigit > 5) ? 1 : 0;
        str[n - 1] = '0';
        for (int i = n - 2; i >= 0 && carry; i--)
        {
            int currDigit = str[i] - '0';
            if (currDigit == 9)
                str[i] = '0';
            else
                str[i]++, carry = 0;
        }

        // If carry is still remaining, add '1' to start of string
        if (carry)
            str = "1" + str;
        return str;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    String roundToNearest(String str)
    {
        int n = str.length();
        int lastDigit = str.charAt(n - 1) - '0';
        int carry = (lastDigit > 5) ? 1 : 0;
        char[] ch = str.toCharArray();
        ch[n - 1] = '0';

        for (int i = n - 2; i >= 0 && carry > 0; i--)
        {
            int currDigit = ch[i] - '0';
            if (currDigit == 9)
                ch[i] = '0';
            else
            {
                ch[i] += 1;
                carry = 0;
            }
        }

        str = new String(ch);
        if (carry > 0)
            str = "1" + str;

        return str;
    }
}