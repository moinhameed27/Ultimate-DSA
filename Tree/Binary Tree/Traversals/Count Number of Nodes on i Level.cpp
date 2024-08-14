// GFG : https://www.geeksforgeeks.org/problems/introduction-to-trees/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Power)
class Solution
{
public:
    int countNodes(int i)
    {
        return pow(2, i - 1);
    }
};

// Way - II (Recursion)
class Solution
{
public:
    int countNodes(int i)
    {
        if (i == 1)
            return 1;
        return 2 * countNodes(i - 1);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Power)
class Solution
{
    static int countNodes(int i)
    {
        return (int)Math.pow(2, i - 1);
    }
}

// Way - II (Recursion)
class Solution
{
    static int countNodes(int i)
    {
        if (i == 1)
            return 1;
        return 2 * countNodes(i - 1);
    }
}