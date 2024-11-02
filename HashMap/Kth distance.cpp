// GFG : https://www.geeksforgeeks.org/problems/kth-distance3757/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool checkDuplicatesWithinK(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) != mp.end())
            {
                if (i - mp[arr[i]] <= k)
                    return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    boolean checkDuplicatesWithinK(int arr[], int k)
    {
        int n = arr.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++)
        {
            if (mp.containsKey(arr[i]))
            {
                if (i - mp.get(arr[i]) <= k)
                    return true;
            }
            mp.put(arr[i], i);
        }
        return false;
    }
}