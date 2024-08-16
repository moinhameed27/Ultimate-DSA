// Leetcode : https://leetcode.com/problems/maximum-distance-in-arrays/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [2 Pass])
/*
1. Find the maximum and minimum element in the first array along with storing their indices.
2. Find the minimum from different array from which maximum element was chosen.
3. Find the maximum from different array from which minimum element was chosen.
*/
class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int m = arrays.size();
        int min1 = INT_MAX, max1 = INT_MIN;
        int min2 = INT_MAX, max2 = INT_MIN;
        int minIdx = -1, maxIdx = -1;
        for (int i = 0; i < m; i++)
        {
            int n = arrays[i].size();
            if (arrays[i][0] < min1)
                min1 = arrays[i][0], minIdx = i;
            if (arrays[i][n - 1] > max2)
                max2 = arrays[i][n - 1], maxIdx = i;
        }
        for (int i = 0; i < m; i++)
        {
            int n = arrays[i].size();
            if (i != minIdx)
                max1 = max(max1, arrays[i][n - 1]);
            if (i != maxIdx)
                min2 = min(min2, arrays[i][0]);
        }
        return max(max1 - min1, max2 - min2);
    }
};

// Way - II (One Pass)
/*
1. Find the minimum and maximum element from first array.
2. Compare the next array with the current minimum and maximum element && current maximum and minimum element.
3. Update the minimum and maximum element accordingly.
*/
class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int n = arrays.size();
        int minElement = arrays[0].front(), maxElement = arrays[0].back();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            ans = max({ans, abs(maxElement - currMin), abs(minElement - currMax)});

            minElement = min(minElement, currMin);
            maxElement = max(maxElement, currMax);
        }
        return ans;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [2 Pass])
class Solution
{
    public int maxDistance(List<List<Integer>> arrays)
    {
        int m = arrays.size();
        int min1 = Integer.MAX_VALUE, max1 = Integer.MIN_VALUE;
        int min2 = Integer.MAX_VALUE, max2 = Integer.MIN_VALUE;
        int minIdx = -1, maxIdx = -1;
        for (int i = 0; i < m; i++)
        {
            int n = arrays.get(i).size();
            if (arrays.get(i).get(0) < min1)
            {
                min1 = arrays.get(i).get(0);
                minIdx = i;
            }
            if (arrays.get(i).get(n - 1) > max2)
            {
                max2 = arrays.get(i).get(n - 1);
                maxIdx = i;
            }
        }
        for (int i = 0; i < m; i++)
        {
            int n = arrays.get(i).size();
            if (i != minIdx)
                max1 = Math.max(max1, arrays.get(i).get(n - 1));
            if (i != maxIdx)
                min2 = Math.min(min2, arrays.get(i).get(0));
        }
        return Math.max(max1 - min1, max2 - min2);
    }
}

// Way - II (One Pass)
class Solution
{
    public int maxDistance(List<List<Integer>> arrays)
    {
        int n = arrays.size();
        int minElement = arrays.get(0).get(0), maxElement = arrays.get(0).get(arrays.get(0).size() - 1);
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            int currMin = arrays.get(i).get(0);
            int currMax = arrays.get(i).get(arrays.get(i).size() - 1);

            ans = Math.max(ans, Math.max(Math.abs(maxElement - currMin), Math.abs(minElement - currMax)));

            minElement = Math.min(minElement, currMin);
            maxElement = Math.max(maxElement, currMax);
        }

        return ans;
    }
}