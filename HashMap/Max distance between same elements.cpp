// GFG : https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int maxDistance(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int n = arr.size();
        int dist = -1;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) != mp.end())
                dist = max(dist, i - mp[arr[i]]);
            else
                mp[arr[i]] = i;
        }
        return dist;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    int maxDistance(int[] arr)
    {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = arr.length;
        int dist = -1;
        for (int i = 0; i < n; i++)
        {
            if (mp.containsKey(arr[i]))
                dist = Math.max(dist, i - mp.get(arr[i]));
            else
                mp.put(arr[i], i);
        }
        return dist;
    }
}