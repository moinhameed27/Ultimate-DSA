// Leetcode : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/

/*
1. 1 push is required to type the first character.
2. 2 pushes are required to type the characters after 8.
3. 3 pushes are required to type the characters after 16.
4. 4 pushes are required to type the characters after 24.
*/
// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n) time and O(1) space
class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.size();
        if (n <= 8)
            return n;
        int pushes = 0, press = 1;
        for (int i = 0; i < n; i++)
        {
            pushes += press;
            if ((i + 1) % 8 == 0)
                press++;
        }
        return pushes;
    }
};

// Way - II (Constant Time) : O(1) time and O(1) space
class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.size();
        if (n <= 8)
            return n;
        else if (n <= 16)
            return 8 + ((n - 8) * 2);
        else if (n <= 24)
            return 24 + ((n - 16) * 3);
        else
            return 48 + ((n - 24) * 4);
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n) time and O(1) space
class Solution
{
public
    int minimumPushes(String word)
    {
        int n = word.length();
        // Only n pushes are required if n <= 8
        if (n <= 8)
            return n;
        int pushes = 0, press = 1;
        for (int i = 0; i < n; i++)
        {
            pushes += press;
            if ((i + 1) % 8 == 0)
                press++;
        }
        return pushes;
    }
}

// Way - II (Constant Time) : O(1) time and O(1) space
class Solution
{
public
    int minimumPushes(String word)
    {
        int n = word.length();
        if (n <= 8)
            return n;
        else if (n <= 16)
            return 8 + ((n - 8) * 2);
        else if (n <= 24)
            return 24 + ((n - 16) * 3);
        else
            return 48 + ((n - 24) * 4);
    }
}