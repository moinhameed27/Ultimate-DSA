// GFG : https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int Maximize(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long ans = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++)
            ans = (ans + ((long)i * arr[i])) % MOD;
        return (int)ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    int Maximize(int arr[])
    {
        Arrays.sort(arr);
        int n = arr.length;
        long ans = 0;
        int MOD = 1000000007;
        for (int i = 0; i < n; i++)
            ans = (ans + ((long)i * arr[i])) % MOD;
        return (int)ans;
    }
}