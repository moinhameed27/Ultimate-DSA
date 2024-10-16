// GFG : https://www.geeksforgeeks.org/problems/two-swaps--155623/1

/* 
1. Since arr[i] element should be at (arr[i] - 1) place as array is 0-indexed.
2. So replacing arr[i] with arr[arr[i] - 1] will make the array sorted.
3. If we are able to make the array sorted in 2 or 0 swaps then return true else return false.
*/
// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    bool checkSorted(vector<int> &arr)
    {
        int n = arr.size();
        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
                swaps++;
                i--;
            }
        }

        if (swaps == 2 || swaps == 0)
            return true;
        else
            return false;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
class Solution 
{

    public boolean checkSorted(List<Integer> arr) 
    {
        int n = arr.size();
        int swaps = 0;

        for (int i = 0; i < n; i++) 
        {
            if (arr.get(i) != i + 1) 
            {
                int temp = arr.get(i);
                arr.set(i, arr.get(temp - 1));
                arr.set(temp - 1, temp);
                swaps++;
                i--;
            }
        }

        if (swaps == 2 || swaps == 0)
            return true;
        else
            return false;
    }
}