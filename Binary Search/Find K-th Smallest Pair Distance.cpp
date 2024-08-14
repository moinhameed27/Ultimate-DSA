// Leetcode : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force I)
/* Find all pairs and store their distances, sort the distances and return (k - 1)th index  */
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> distances;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(nums[i] - nums[j]);
                distances.push_back(dist);
            }
        }
        sort(distances.begin(), distances.end());

        return distances[k - 1];
    }
};

// Way - II (Brute Force I [Max Heap]) [TLE]
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(nums[i] - nums[j]);
                pq.push(dist);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

// Way - III (Storing the Frequency of distances) : O(n^2) time and O(M) space
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        // Maximum distance can be between the maximum and minimum element
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> distances(maxi + 1); // To include the maximum element

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(nums[i] - nums[j]);
                distances[dist]++;
            }
        }

        // Find the kth smallest distance
        for (int i = 0; i <= maxi; i++)
        {
            k -= distances[i];
            if (k <= 0)
                return i;
        }

        return -1;
    }
};

// Way - IV (Improvement in Way - I [Partial Sorting]) : O(n^2) time and O(P) space
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> distances;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(nums[i] - nums[j]);
                distances.push_back(dist);
            }
        }
        // Partial Sort the array and bring the (k - 1)th element in it's correct place
        nth_element(distances.begin(), distances.begin() + (k - 1), distances.end());

        return distances[k - 1];
    }
};

// Way - V (Sorting + Binary Search + Sliding Window) : O(nlogn) time and O(1) space
/*
1. Sort the array
2. Find the minimum and maximum distance between the elements
3. Apply Binary Search on the distances
4. For each distance, find the number of pairs whose distance is less than or equal to the current distance.
5. If the number of pairs is less than k, then the answer lies in the right half of the distance
6. If the number of pairs is greater than or equal to k, then the answer lies in the left half of the distance
7. Return the distance when the number of pairs is equal to k
*/
class Solution
{
    int slidingWindowCount(vector<int> &nums, int dist)
    {
        int i = 0, j = 1, n = nums.size();
        int count = 0;
        while (j < n)
        {
            while (nums[j] - nums[i] > dist)
                i++;
            count += j - i;
            j++;
        }
        return count;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0, right = nums[n - 1] - nums[0];

        // Binary Search on the distances
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // Sliding window to find the number of pairs whose distance is less than or equal to mid
            int pairsCount = slidingWindowCount(nums, mid);

            if (pairsCount < k)
                left = mid + 1;
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Storing the Frequency of distances) : O(n^2) time and O(M) space
class Solution
{
    public int smallestDistancePair(int[] nums, int k)
    {
        int n = nums.length;
        // Maximum distance can be between the maximum and minimum element
        int maxi = Arrays.stream(nums).max().getAsInt();
        int[] distances = new int[maxi + 1]; // To include the maximum element

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = Math.abs(nums[i] - nums[j]);
                distances[dist]++;
            }
        }

        // Find the kth smallest distance
        for (int i = 0; i <= maxi; i++)
        {
            k -= distances[i];
            if (k <= 0)
                return i;
        }

        return -1;
    }
}

// Way - II (Sorting + Binary Search + Sliding Window) : O(nlogn) time and O(1) space
class Solution
{
    private int slidingWindowCount(int[] nums, int dist)
    {
        int i = 0, j = 1, n = nums.length;
        int count = 0;
        while (j < n)
        {
            while (nums[j] - nums[i] > dist)
                i++;
            count += j - i;
            j++;
        }
        return count;
    }
    public int smallestDistancePair(int[] nums, int k)
    {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = 0;
        int left = 0, right = nums[n - 1] - nums[0];

        // Binary Search on the distances
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // Sliding window to find the number of pairs whose distance is less than or equal to mid
            int pairsCount = slidingWindowCount(nums, mid);

            if (pairsCount < k)
                left = mid + 1;
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
}
