// Leetcode : https://leetcode.com/problems/integer-to-english-words

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    // Below Twenty and tenth place are special characters which cannot be derived from the pattern
    unordered_map<int, string> belowTen = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
    unordered_map<int, string> belowTwenty = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
    unordered_map<int, string> belowHundred = {{1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

    string solve(int num)
    {
        if (num < 10)
            return belowTen[num];
        if (num < 20)
            return belowTwenty[num];
        // e.g 21 --> Twenty One, 20 --> Twenty
        if (num < 100)
            return belowHundred[num / 10] + ((num % 10 != 0) ? " " + belowTen[num % 10] : "");
        // e.g 100 --> One Hundred, 101 --> One Hundred One, 110 --> One Hundred Ten
        if (num < 1000)
            return solve(num / 100) + " Hundred" + ((num % 100 != 0) ? " " + solve(num % 100) : "");
        // e.g 1000 --> One Thousand, 1001 --> One Thousand One, 1010 --> One Thousand Ten
        if (num < 1000000)
            return solve(num / 1000) + " Thousand" + ((num % 1000 != 0) ? " " + solve(num % 1000) : "");
        // e.g 1000000 --> One Million, 1000001 --> One Million One, 1000010 --> One Million Ten
        if (num < 1000000000)
            return solve(num / 1000000) + " Million" + ((num % 1000000) != 0 ? " " + solve(num % 1000000) : "");

        // e.g 1000000000 --> One Billion, 1000000001 --> One Billion One, 1000000010 --> One Billion Ten
        return solve(num / 1000000000) + " Billion" + ((num % 1000000000) != 0 ? " " + solve(num % 1000000000) : "");
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        return solve(num);
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
class Solution
{
private final String[] belowTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
private final String[] belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
private final String[] belowHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

public String numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        return solve(num);
    }

private String solve(int num)
    {
        if (num < 10)
            return belowTen[num];
        if (num < 20)
            return belowTwenty[num - 10];
        if (num < 100)
            return belowHundred[num / 10] + ((num % 10 != 0) ? " " + solve(num % 10) : "");
        if (num < 1000)
            return solve(num / 100) + " Hundred" + ((num % 100 != 0) ? " " + solve(num % 100) : "");
        if (num < 1000000)
            return solve(num / 1000) + " Thousand" + ((num % 1000 != 0) ? " " + solve(num % 1000) : "");
        if (num < 1000000000)
            return solve(num / 1000000) + " Million" + ((num % 1000000) != 0 ? " " + solve(num % 1000000) : "");
        return solve(num / 1000000000) + " Billion" + ((num % 1000000000) != 0 ? " " + solve(num % 1000000000) : "");
    }
}