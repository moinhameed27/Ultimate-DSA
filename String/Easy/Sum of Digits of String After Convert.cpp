// Leetcode : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
public:
    int getLucky(string s, int k)
    {
        string number = "";
        // Convert alphabets into number by their ASCII value
        for (char str : s)
            number += to_string(str - 'a' + 1);

        while (k > 0)
        {
            int temp = 0;
            for (char x : number)
                temp += x - '0';

            number = to_string(temp);
            k--;
        }
        return stoi(number);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    public int getLucky(String s, int k)
    {
        StringBuilder number = new StringBuilder();
        // Convert alphabets into number by their ASCII value
        for (char str : s.toCharArray())
            number.append(str - 'a' + 1);

        while (k > 0)
        {
            int temp = 0;
            for (char x : number.toString().toCharArray())
                temp += x - '0';

            number = new StringBuilder().append(temp);
            k--;
        }
        return Integer.parseInt(number.toString());
    }
}