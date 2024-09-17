// GFG :

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        if (n == 1)
            return 0;
        sort(arr, arr + n);
        int mini = arr[0], maxi = arr[n - 1];
        int minDiff = maxi - mini;

        for (int i = 1; i < n; i++)
        {
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
    int getMinDiff(int[] arr, int n, int k)
    {
        if (n == 1)
            return 0;
        Arrays.sort(arr);
        int mini = arr[0], maxi = arr[n - 1];
        int minDiff = maxi - mini;

        for (int i = 1; i < n; i++)
        {
            // Minimum can be either arr[0] + k or arr[i] - k
            mini = Math.min(arr[0] + k, arr[i] - k);
            // Maximum can be either arr[i - 1] + k or arr[n - 1] - k
            maxi = Math.max(arr[i - 1] + k, arr[n - 1] - k);
            minDiff = Math.min(minDiff, maxi - mini);
        }
        return minDiff;
    }
}