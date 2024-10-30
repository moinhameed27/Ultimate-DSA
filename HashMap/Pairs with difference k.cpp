// GFG :

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space [TLE]
class Solution
{
public:
    int countPairsWithDiffK(vector<int> &arr, int k)
    {
        int n = arr.size(), ans = 0;
        int i = 0, j = n - 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(arr[i] - arr[j]) == k)
                    ans++;
            }
        }
        return ans;
    }
};

// Way - II (HashMap) : O(n) time and O(n) space
class Solution
{
public:
    int countPairsWithDiffK(vector<int> &arr, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int num : arr)
            mp[num]++;

        for (auto it : mp)
        {
            int num = it.first, count = it.second;
            if (mp.find(num + k) != mp.end())
                ans += count * mp[num + k];
        }

        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space [TLE]
class Solution 
{
    int countPairsWithDiffK(int[] arr, int k) 
    {
        int n = arr.length, ans = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (Math.abs(arr[i] - arr[j]) == k) 
                    ans++;
            }
        }
        return ans;
    }
}

// Way - II (HashMap) : O(n) time and O(n) space
class Solution 
{
    int countPairsWithDiffK(int[] arr, int k) 
    {
        int ans = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int num : arr) 
            mp.put(num, mp.getOrDefault(num, 0) + 1);

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) 
        {
            int num = entry.getKey(), count = entry.getValue();
            if (mp.containsKey(num + k)) 
                ans += count * mp.get(num + k);
        }

        return ans;
    }
}