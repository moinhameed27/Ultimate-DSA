// GFG : https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
            return 0;
        sort(arr.begin(), arr.end());
        int mini = arr[0], maxi = arr[n - 1];
        int minDiff = maxi - mini;

        for (int i = 1; i < n; i++)
        {
            // If operation results in negative height, then skip that operation
            if (arr[i] - k < 0)
                continue;
            // Minimum can be either arr[0] + k or arr[i] - k
            mini = min(arr[0] + k, arr[i] - k);
            // Maximum can be either arr[i - 1] + k or arr[n - 1] - k
            maxi = max(arr[i - 1] + k, arr[n - 1] - k);
            minDiff = min(minDiff, maxi - mini);
        }
        return minDiff;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    int getMinDiff(int[] arr, int k)
    {
        int n = arr.length;
        if (n == 1)
            return 0;
        Arrays.sort(arr);
        int mini = arr[0], maxi = arr[n - 1];
        int minDiff = maxi - mini;

        for (int i = 1; i < n; i++)
        {
            // If operation results in negative height, then skip that operation
            if (arr[i] - k < 0)
                continue;
            // Minimum can be either arr[0] + k or arr[i] - k
            mini = Math.min(arr[0] + k, arr[i] - k);
            // Maximum can be either arr[i - 1] + k or arr[n - 1] - k
            maxi = Math.max(arr[i - 1] + k, arr[n - 1] - k);
            minDiff = Math.min(minDiff, maxi - mini);
        }
        return minDiff;
    }
}