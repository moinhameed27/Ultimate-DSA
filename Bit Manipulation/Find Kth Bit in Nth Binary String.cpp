// Leetcode : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
    string invertBits(string str)
    {
        for (char &ch : str)
        {
            if (ch == '0')
                ch = '1';
            else
                ch = '0';
        }
        return str;
    }

public:
    char findKthBit(int n, int k)
    {
        string str = "0"; // Initial string
        // Until n, keep on generating string after appending 1 and reversing the inverted string each time
        for (int i = 1; i < n; i++)
        {
            string str2 = invertBits(str);
            reverse(str2.begin(), str2.end());
            str = str + "1" + str2;
        }
        return str[k - 1];
    }
};

// Way - II (Recursion)
class Solution
{
    string invertAndReverse(string str)
    {
        for (char &ch : str)
        {
            if (ch == '0')
                ch = '1';
            else
                ch = '0';
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string solve(int n)
    {
        // Initial given string
        if (n == 1)
            return "0";

        string str = solve(n - 1);
        return str + "1" + invertAndReverse(str);
    }

public:
    char findKthBit(int n, int k)
    {
        string str = solve(n);

        return str[k - 1];
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
    public char findKthBit(int n, int k)
    {
        String str = "0"; // Initial string
        // Until n, keep on generating string after appending 1 and reversing the inverted string each time
        for (int i = 1; i < n; i++)
        {
            str = str + "1" + new StringBuilder(str).reverse().toString().replace('0', '2').replace('1', '0').replace('2', '1');
        }
        return str.charAt(k - 1);
    }
}

// Way - II (Recursion)
class Solution
{
    private String invertAndReverse(String str)
    {
        StringBuilder sb = new StringBuilder();
        for (char ch : str.toCharArray())
        {
            if (ch == '0')
                sb.append('1');
            else
                sb.append('0');
        }
        return sb.reverse().toString();
    }

    private String solve(int n)
    {
        // Initial given string
        if (n == 1)
            return "0";

        String str = solve(n - 1);
        return str + "1" + invertAndReverse(str);
    }

    public char findKthBit(int n, int k)
    {
        String str = solve(n);

        return str.charAt(k - 1);
    }
}