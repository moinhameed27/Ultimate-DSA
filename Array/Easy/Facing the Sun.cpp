// GFG : https://www.geeksforgeeks.org/problems/facing-the-sun2126/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height)
    {
        int ans = 0, leftMax = INT_MIN;
        for (int i : height)
        {
            if (i > leftMax)
            {
                leftMax = i;
                ans++;
            }
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    int countBuildings(int h[]) 
    {
        int ans = 0, leftMax = Integer.MIN_VALUE;
        for (int i : h) 
        {
            if (i > leftMax) 
            {
                leftMax = i;
                ans++;
            }
        }
        return ans;
    }
}