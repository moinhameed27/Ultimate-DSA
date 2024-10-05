// GFG : https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    long long findSmallest(vector<int> &arr)
    {
        long long ans = 1;
        for (int num : arr)
        {
            if (num > ans)
                break;
            ans += num;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public long findSmallest(int[] arr) 
    {
        long ans = 1;
        for(int num : arr)
        {
            if(num > ans)
                break;
            ans += num;
        }
        return ans;
    }
}