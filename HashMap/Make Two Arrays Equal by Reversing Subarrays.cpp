// LeetCode : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

// Way - I (Hashmap) --> O(n) time, O(n) space
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> mp;
        // Store elements of one target array
        for (int i : target)
            mp[i]++;

        // Check if elements of other array are present in the map
        for (int j : arr)
        {
            if (mp.find(j) != mp.end() && mp[j] > 0)
                mp[j]--;
            else
                return false;
        }
        return true;
    }
};

// Way - II (Sorting)
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        int n = target.size();
        // Sort both arrays
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        // Compare them
        for (int i = 0; i < n; i++)
        {
            if (target[i] != arr[i])
                return false;
        }
        return true;
    }
};