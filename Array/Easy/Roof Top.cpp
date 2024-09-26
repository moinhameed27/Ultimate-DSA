// GFG : https://www.geeksforgeeks.org/problems/roof-top-1587115621/1

// [C++]-----------------------------------------------------------------------------------------------------------------------

class Solution
{
public:
    int maxStep(vector<int> &arr)
    {
        int steps = 0, ans = INT_MIN;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                steps++;
                ans = max(ans, steps);
            }
            else
                steps = 0;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public int maxStep(int arr[]) 
    {
        int steps = 0, ans = Integer.MIN_VALUE;
        int n = arr.length;
        for (int i = 1; i < n; i++) 
        {
            if (arr[i] > arr[i - 1]) 
            {
                steps++;
                ans = Math.max(ans, steps);
            } 
            else
                steps = 0;
        }
        return ans;
    }
}