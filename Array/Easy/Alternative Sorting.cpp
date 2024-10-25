// GFG : https://www.geeksforgeeks.org/problems/alternative-sorting1311/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{

public:
    vector<int> alternateSort(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        int i = 0, j = n - 1, k = 0;
        while (i <= j)
        {
            ans[k++] = arr[j--];
            if (i <= j)
                ans[k++] = arr[i++];
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public static ArrayList<Integer> alternateSort(int[] arr) 
    {
        int n = arr.length;
        Arrays.sort(arr);
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0, j = n - 1;
        while (i <= j) 
        {
            ans.add(arr[j--]);
            if (i <= j) 
                ans.add(arr[i++]);
        }
        return ans;
    }
}