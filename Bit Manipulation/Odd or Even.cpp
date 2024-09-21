// GFG : https://www.geeksforgeeks.org/problems/odd-or-even3618/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Modulo)
class Solution
{
public:
    string oddEven(int n)
    {
        return n % 2 == 0 ? "even" : "odd";
    }
};

// Way - II (Bitwise)
class Solution
{
public:
    string oddEven(int n)
    {
        return (1 & n == 0) ? "even" : "odd";
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Modulo)
class Solution
{
    static String oddEven(int n)
    {
        return n % 2 == 0 ? "even" : "odd";
    }
}

// Way - II (Bitwise)
class Solution
{
    static String oddEven(int n)
    {
        return ((1 & n) == 0) ? "even" : "odd";
    }
}