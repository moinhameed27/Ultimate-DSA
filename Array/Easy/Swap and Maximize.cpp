// GFG : https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{

public:
    long long maxSum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long sum = 0;
        int i = 0, j = arr.size() - 1;
        while (i < j)
            sum += abs(arr[i++] - arr[j--]);
        return 2 * sum;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public long maxSum(Long[] arr)
    {
        Arrays.sort(arr);
        long sum = 0;
        int i = 0, j = arr.length - 1;
        while (i < j)
            sum += Math.abs(arr[i++] - arr[j--]);

        return 2 * sum;
    }
}