// GFG : https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    void bitManipulation(int num, int i)
    {
        int get = ((num >> (i - 1)) & 1);
        int set = (num | (1 << (i - 1)));
        int clear = set ^ (1 << (i - 1));
        cout << get << " " << set << " " << clear;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    static void bitManipulation(int num, int i) 
    {
        int get = ((num >> (i - 1)) & 1);
        int set = (num | (1 << (i - 1)));
        int clear = set ^ (1 << (i - 1));
        System.out.println(get + " " + set + " " + clear);    
    }
}