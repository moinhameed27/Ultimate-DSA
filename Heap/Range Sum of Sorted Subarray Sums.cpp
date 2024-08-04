// Leetcode : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/

// Way - I (Brute Force)
/* Find all subarray sums and get the sum of the required subarray after sorting. */
class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> subarray;
        // Storing all subarrays into another array
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                subarray.push_back(sum);
            }
        }

        // Sort the array
        sort(subarray.begin(), subarray.end());
        int ans = 0;
        int mod = 1e9 + 7;
        // Get the required subarray sum
        for (int i = left - 1; i < right; i++)
            ans = (ans + subarray[i]) % mod;

        return ans;
    }
};

// Way - II (Priority Queue[Min Heap])
/*
1. Store the subarray sum (initially the smallest subarray meaning array elements) and the ending index in the priority queue.
2. Pop the minimum element from the priority queue and add it to the answer if the count is between left and right.
3. Add the next element to the popped element and push it back to the priority queue after adding the next element.
4. Repeat the above steps until the count reaches the right.
*/
class Solution
{
public:
    typedef pair<int, int> P; // {Subarray sum, ending index}
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        const int MOD = 1e9 + 7;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        int ans = 0;
        for (int count = 1; count <= right; count++)
        {
            auto top = pq.top();
            pq.pop();
            if (count >= left)
                ans = (ans + top.first) % MOD;
            int newIdx = top.second + 1;
            if (newIdx < n)
            {
                P newPair;
                newPair.first = top.first + nums[newIdx];
                newPair.second = newIdx;
                pq.push(newPair);
            }
        }
        return ans;
    }
};