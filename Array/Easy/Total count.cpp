// GFG : https://www.geeksforgeeks.org/problems/total-count2415/1

/* Take the ceil of the number to check how many times the number can be divided by k for it's sum. */
// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int totalCount(int k, vector<int> &arr)
    {
        int ans = 0;
        for (int num : arr)
            ans += ceil(double(num) / k);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    int totalCount(int k, int[] arr)
    {
        int ans = 0;
        for (int num : arr)
            ans += Math.ceil((double)num / k);
        return ans;
    }
}