// Leetcode : https://leetcode.com/problems/number-complement/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Flipping Bits One by one) : O(log2(num)) time and O(1) space
/*
num = 5
i = 0, flip = 1 << 0 --> 001
101 ^ 001 = 100
i = 1, flip = 1 << 1 --> 010
100 ^ 010 = 110
i = 3, flip = 1 << 2 --> 100
110 ^ 100 = 010
*/
class Solution
{
public:
    int findComplement(int num)
    {
        int bits = log2(num) + 1;

        for (int i = 0; i < bits; i++)
            num ^= (1 << i);
        return num;
    }
};

// Way - II (Flipping Bits all at once) : O(log2(num)) time and O(1) space
/*
num = 5
101 ^ 111 = 010
bits = 3, mask = 1 << 3 --> 100 , (1 << 3) - 1 --> 011
*/
class Solution
{
public:
    int findComplement(int num)
    {
        int bits = log2(num) + 1;

        unsigned int mask = (1U << bits) - 1;
        return num ^ mask;
    }
};

// Way - III (OR Operator [Iterating bit by bit]) : : O(log2(num)) time and O(1) space
/*
--> num = 5, i = 0, ans = 0
101 & 001 = 1
--> num = 2, i = 1, ans = 0
010 & 001 = 0
001 << 1 = 010
010 | 010 = 010
--> num = 1, i = 2, ans = 1
001 && 001 = 1
Answer = 1 (010)
1. Right shift num in every iteration, so that each bits comes to the first place.
2. Check the parity of bit by taking & with 1, if it is 1, then answer already has flipped that to zero.
3. If it is 0, then first go to that number of bit by taking (i << i) and then take or with answer to make it 1.
*/
class Solution
{
public:
    int findComplement(int num)
    {
        int i = 0, ans = 0;
        while (num)
        {
            // If current bit is 0, set the bit to 1
            if (!(num & 1))
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Flipping Bits One by one) : : O(log2(num)) time and O(1) space
class Solution
{
    public int findComplement(int num)
    {
        int bits = (int)(Math.log(num) / Math.log(2)) + 1;

        for (int i = 0; i < bits; i++)
            num ^= (1 << i);
        return num;
    }
}

// Way - II (Flipping Bits all at once) : O(log2(num)) time and O(1) space
class Solution
{
    public int findComplement(int num)
    {
        int bits = (int)(Math.log(num) / Math.log(2)) + 1;

        int mask = (1 << bits) - 1;
        return num ^ mask;
    }
}

// Way - III (OR Operator [Iterating bit by bit]) : : O(log2(num)) time and O(1) space
class Solution
{
    public int findComplement(int num)
    {
        int i = 0, ans = 0;
        while (num > 0)
        {
            // If current bit is 0, set the bit to 1
            if ((num & 1) == 0)
                ans |= (1 << i);
            num >>= 1;
            i++;
        }
        return ans;
    }
}