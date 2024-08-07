// GFG : https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O((n + m)log(n + m)) time and O(n + m) space
/* Merge all elements, sort them and get the kth element */
class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        for (int i : arr2)
            arr1.push_back(i);
        sort(arr1.begin(), arr1.end());
        return arr1[k - 1];
    }
};

// Way - II (Priority Queue [Min Heap]) : O((n + m)log(n + m)) time and O(n + m) space
/* Push all elements into Min Heap, and get the kth element */
class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : arr1)
            pq.push(i);
        for (int i : arr2)
            pq.push(i);
        int c = 0;
        while (!pq.empty())
        {
            c++;
            if (c == k)
                return pq.top();
            pq.pop();
        }
        return -1;
    }
};

// Way - III (Two Pointers) : O(m + n) time and O(1) space
class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        int m = arr1.size(), n = arr2.size();
        int a = 0, b = 0, c = 0;
        // Keep traversing until one of the array is exhausted
        while (a < m && b < n)
        {
            bool inArray1 = false, inArray2 = false;
            if (arr1[a] <= arr2[b])
            {
                a++;
                inArray1 = true;
            }
            else
            {
                b++;
                inArray2 = true;
            }
            c++;
            if (c == k)
            {
                if (inArray1)
                    return arr1[a - 1];
                else
                    return arr2[b - 1];
            }
        }
        // If array2 is exhausted
        while (a < m)
        {
            a++;
            c++;
            if (c == k)
                return arr1[a - 1];
        }

        // If array1 is exhausted
        while (b < n)
        {
            b++;
            c++;
            if (c == k)
                return arr2[b - 1];
        }
        return 0;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O((n + m)log(n + m)) time and O(n + m) space
/* Merge all elements, sort them and get the kth element */
class Solution
{
public
    int kthElement(int k, int[] arr1, int[] arr2)
    {
        int n = arr1.length, m = arr2.length;
        int[] arr = new int[n + m];
        for (int i = 0; i < n; i++)
            arr[i] = arr1[i];
        for (int i = 0; i < m; i++)
            arr[n + i] = arr2[i];
        Arrays.sort(arr);
        return arr[k - 1];
    }
}

// Way - II (Priority Queue [Min Heap]) : O((n + m)log(n + m)) time and O(n + m) space
/* Push all elements into Min Heap, and get the kth element */
class Solution
{
public
    int kthElement(int k, int[] arr1, int[] arr2)
    {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i : arr1)
            pq.add(i);
        for (int i : arr2)
            pq.add(i);
        int c = 0;
        while (!pq.isEmpty())
        {
            c++;
            if (c == k)
                return pq.poll();
            pq.poll();
        }
        return -1;
    }
}

// Way - III (Two Pointers) : O(m + n) time and O(1) space
class Solution
{
public
    int kthElement(int k, int[] arr1, int[] arr2)
    {
        int m = arr1.length, n = arr2.length;
        int a = 0, b = 0, c = 0;
        // Keep traversing until one of the array is exhausted
        while (a < m && b < n)
        {
            boolean inArray1 = false, inArray2 = false;
            if (arr1[a] <= arr2[b])
            {
                a++;
                inArray1 = true;
            }
            else
            {
                b++;
                inArray2 = true;
            }
            c++;
            if (c == k)
            {
                if (inArray1)
                    return arr1[a - 1];
                else
                    return arr2[b - 1];
            }
        }
        // If array2 is exhausted
        while (a < m)
        {
            a++;
            c++;
            if (c == k)
                return arr1[a - 1];
        }

        // If array1 is exhausted
        while (b < n)
        {
            b++;
            c++;
            if (c == k)
                return arr2[b - 1];
        }
        return 0;
    }
}