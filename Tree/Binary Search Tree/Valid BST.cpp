// GFG : https://www.geeksforgeeks.org/problems/binary-search-trees/1

/* Check if array is sorted and no consecutive elements are same */
// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool isBSTTraversal(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] <= arr[i - 1])
                return false;
        }
        return true;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    static boolean isBSTTraversal(int[] arr)
    {
        for (int i = 1; i < arr.length; i++)
        {
            if (arr[i] <= arr[i - 1])
                return false;
        }
        return true;
    }
}