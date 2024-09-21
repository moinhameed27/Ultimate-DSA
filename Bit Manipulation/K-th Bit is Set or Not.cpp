// GFG : https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        return (n & (1 << k));
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class CheckBit
{
    static boolean checkKthBit(int n, int k)
    {
        return (n & (1 << k)) != 0;
    }
}