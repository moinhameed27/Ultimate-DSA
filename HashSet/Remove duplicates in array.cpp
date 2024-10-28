// GFG : https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr)
    {
        unordered_set<int> st;
        vector<int> ans;
        for (int num : arr)
        {
            if (!st.count(num))
                ans.push_back(num);
            st.insert(num);
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution 
{
    ArrayList<Integer> removeDuplicate(int arr[]) 
    {
        HashSet<Integer> st = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) 
        {
            if (!st.contains(arr[i])) 
            {
                st.add(arr[i]);
                ans.add(arr[i]);
            }
        }
        return ans;
    }
}