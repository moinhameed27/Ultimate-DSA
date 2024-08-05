// Leetcode : https://leetcode.com/problems/kth-distinct-string-in-an-array

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        // Count frequency of every string
        unordered_map<string, int> mp;
        for(string &str : arr)
            mp[str]++;
        
        int count = 0;
        // If current string is distinct, increment count and when count reaches k, return
        for(string &str : arr)
        {
            if(mp[str] == 1)
                count++;
            if(count == k)
                return str;
        }
        return "";
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public String kthDistinct(String[] arr, int k) 
    {
        Map<String, Integer> mp = new HashMap<>();
        for(String str : arr)
            mp.put(str, mp.getOrDefault(str, 0) + 1);
        
        int count = 0;
        for(String str : arr)
        {
            if(mp.get(str) == 1)
                count++;
            if(count == k)
                return str;
        }
        return "";
    }
}