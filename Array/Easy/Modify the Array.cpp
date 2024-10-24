// GFG : https://www.geeksforgeeks.org/problems/ease-the-array0633/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }

        vector<int> ans(n, 0);
        int i = 0, j = 0;
        while (j < n)
        {
            if (arr[j] != 0)
                ans[i++] = arr[j];
            j++;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution 
{
    static ArrayList<Integer> modifyAndRearrangeArr(int arr[]) 
    {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) 
        {
            if (arr[i] == arr[i + 1]) 
            {
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) 
        {
            if (arr[i] != 0) 
                ans.add(arr[i]);
        }

        while (ans.size() < n) 
            ans.add(0);

        return ans;
    }
}