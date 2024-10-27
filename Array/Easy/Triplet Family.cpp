// GFG : https://www.geeksforgeeks.org/problems/triplet-family/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I(HashSet) : O(n ^ 2) time and O(n) space
class Solution
{
public:
    bool findTriplet(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> nums;
        for (int num : arr)
            nums.insert(num);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums.count(arr[i] + arr[j]))
                    return true;
            }
        }
        return false;
    }
};

// Way - II (Sorting + Two Pointer) : O(n ^ 2) time and O(1) space
class Solution
{
public:
    bool findTriplet(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            int j = 0, k = i;
            while (j < k)
            {
                if (arr[j] + arr[k] == arr[i])
                    return true;
                else if (arr[j] + arr[k] > arr[i])
                    k--;
                else
                    j++;
            }
        }
        return false;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I(HashSet) : O(n ^ 2) time and O(n) space
class Solution 
{
    public boolean findTriplet(int arr[]) 
    {
        int n = arr.length;
        Set<Integer> nums = new HashSet<>();
        for (int num : arr)
            nums.add(num);

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++)
                if (nums.contains(arr[i] + arr[j]))
                    return true;
        }
        return false;
    }
}

// Way - II (Sorting + Two Pointer) : O(n ^ 2) time and O(1) space
class Solution 
{
    public boolean findTriplet(int arr[]) 
    {
        int n = arr.length;
        Arrays.sort(arr);

        for (int i = 0; i < n; i++) 
        {
            int j = 0, k = i;
            while (j < k) 
            {
                if (arr[j] + arr[k] == arr[i])
                    return true;
                else if (arr[j] + arr[k] > arr[i])
                    k--;
                else
                    j++;
            }
        }
        return false;
    }
}