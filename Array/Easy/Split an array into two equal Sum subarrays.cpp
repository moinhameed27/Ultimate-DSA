// GFG : https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

// [C++]----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        int currSum = 0;
        for (int i : arr)
        {
            currSum += i;
            if (currSum * 2 == sum)
                return true;
            else if (currSum * 2 > sum)
                break;
        }
        return false;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public boolean canSplit(int[] arr)
    {
        int sum = 0;
        for (int i : arr)
            sum += i;

        int currSum = 0;
        for (int i : arr)
        {
            currSum += i;
            if (currSum * 2 == sum)
                return true;
            else if (currSum * 2 > sum)
                break;
        }
        return false;
    }
}