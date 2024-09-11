// Leetcode : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Bitset [Binary Representation])
/* Convert the decimal numbers into binary representation of 32. Answer will be number of bits which are different  */
class Solution 
{
public:
    int minBitFlips(int start, int goal) 
    {
        bitset<32> startBits(start), goalBits(goal);
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if(startBits[i] != goalBits[i])
                ans++;
        }
        return ans;
    }
};

// Way - II (Checking Bits in 32 Bit)
class Solution 
{
public:
    int minBitFlips(int start, int goal) 
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (((start >> i) & 1) != ((goal >> i) & 1))
                ans++;
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Bitset [Binary Representation])
/* Convert the decimal numbers into binary representation of 32. Answer will be number of bits which are different  */
class Solution 
{
    public int minBitFlips(int start, int goal) 
    {
        int ans = 0;
        for (int i = 0; i < 32; i++) 
        {
            if (((start >> i) & 1) != ((goal >> i) & 1))
                ans++;
        }
        return ans;
    }
}