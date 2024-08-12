// GFG : https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
/* Middle elements are total / 2 & (total / 2) - 1 */
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        for (int i : arr2)
            arr1.push_back(i);
        sort(arr1.begin(), arr1.end());
        int n = arr1.size();
        int mid1 = n / 2, mid2 = (n / 2) - 1;
        return arr1[mid1] + arr1[mid2];
    }
};

// Way - II (Optimal)
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        int m = arr1.size(), n = arr2.size();
        int mid = (m + n) / 2;

        int a = 0, b = 0, c = 0;
        int ans = 0;

        while (a < m && b < n)
        {
            int value;
            if (arr1[a] <= arr2[b])
                value = arr1[a++];
            else
                value = arr2[b++];

            if (c == mid - 1)
                ans += value;
            if (c == mid)
            {
                ans += value;
                return ans;
            }
            c++;
        }

        while (a < m)
        {
            int value = arr1[a++];
            if (c == mid - 1)
                ans += value;
            if (c == mid)
            {
                ans += value;
                break;
            }
            c++;
        }

        while (b < n)
        {
            int value = arr2[b++];
            if (c == mid - 1)
                ans += value;
            if (c == mid)
            {
                ans += value;
                break;
            }
            c++;
        }
        return ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
/* Middle elements are total / 2 & (total / 2) - 1 */
class Solution
{
    public int SumofMiddleElements(int[] arr1, int[] arr2)
    {
        int n = arr1.length + arr2.length;
        int[] arr = new int[n];
        int i = 0;
        for (int j : arr1)
            arr[i++] = j;
        for (int j : arr2)
            arr[i++] = j;
        Arrays.sort(arr);
        return arr[n / 2] + arr[(n / 2) - 1];
    }
}

// Way - II (Optimal)
class Solution
{
    public int SumofMiddleElements(int[] arr1, int[] arr2)
    {
        int m = arr1.length, n = arr2.length;
        int mid = (m + n) / 2;

        int a = 0, b = 0, c = 0;
        int ans = 0;

        while (a < m && b < n)
        {
            int value;
            if (arr1[a] <= arr2[b])
                value = arr1[a++];
            else
                value = arr2[b++];

            if (c == mid - 1)
                ans += value;
            if (c == mid)
            {
                ans += value;
                return ans;
            }
            c++;
        }

        while (a < m)
        {
            int value = arr1[a++];
            if (c == mid - 1)
                ans += value;
            if (c == mid)
            {
                ans += value;
                break;
            }
            c++;
        }

        while (b < n)
        {
            int value = arr2[b++];
            if (c == mid - 1)
                ans += value;
            if (c == mid)
            {
                ans += value;
                break;
            }
            c++;
        }
        return ans;
    }
}