// GFG : https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    vector<int> rearrange(const vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
                continue;
            ans[arr[i]] = arr[i];
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public List<Integer> rearrange(List<Integer> arr) 
    {
        int n = arr.size();
        List<Integer> ans = new ArrayList<>(Collections.nCopies(n, -1));
        for (int i = 0; i < n; i++) 
        {
            if (arr.get(i) == -1) 
                continue;
            ans.set(arr.get(i), arr.get(i));
        }
        return ans;
    }
}