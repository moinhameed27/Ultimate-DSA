// Leetcode : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Vector of Pointers) : O(n * k) time and O(k) space
/*
1. Create a vector of pointers, each pointing to the first element of the corresponding list.
2. Repeat the following steps until we reach the end of any list:
    a. Find the minimum element and the maximum element among the elements pointed by the pointers.
    b. If the range formed by the maximum and minimum elements is smaller than the current range, update the answer.
    c. Increment the pointer of the list which contains the minimum element.
*/
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        vector<int> pointers(k, 0);
        vector<int> ans = {-100000, 100000};

        while (true)
        {
            int minElement = INT_MAX, maxElement = INT_MIN, minElListIdx = 0;

            for (int i = 0; i < k; i++)
            {
                int listIdx = i;
                int elementIdx = pointers[i];
                int element = nums[listIdx][elementIdx];

                // Update the minimum element and the list index
                if (element < minElement)
                    minElement = element, minElListIdx = listIdx;

                // Update the maximum element
                maxElement = max(maxElement, element);
            }

            // Update the answer
            if (maxElement - minElement < ans[1] - ans[0])
                ans[0] = minElement, ans[1] = maxElement;

            // Break if any list is exhausted
            int nextIdx = pointers[minElListIdx] + 1;
            if (nextIdx == nums[minElListIdx].size())
                break;
            pointers[minElListIdx] = nextIdx;
        }
        return ans;
    }
};
// Way - II (Priority Queue [Min Heap]) : O(n * logk) time and O(k) space
/*
1. Create a min heap to store the elements, list index, and element index.
2. Insert the first element of each list into the min heap.
3. Repeat the following steps until we reach the end of any list:
    a. Extract the minimum element from the min heap.
    b. Update the answer if the range formed by the maximum and minimum elements is smaller than the current range.
    c. Insert the next element of the list from which the minimum element was extracted.
*/
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        vector<int> ans = {-100000, 100000};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        // Insert the first element of each list into the min heap and find the maximum element
        int maxElement = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i][0], i, 0});
            maxElement = max(maxElement, nums[i][0]);
        }

        while (true)
        {
            vector<int> top = pq.top();
            pq.pop();

            int minElement = top[0], listIdx = top[1], elementIdx = top[2];

            // Update the answer
            if (maxElement - minElement < ans[1] - ans[0])
                ans[0] = minElement, ans[1] = maxElement;

            // Break if any list is exhausted
            if (elementIdx + 1 == nums[listIdx].size())
                break;

            int nextElement = nums[listIdx][elementIdx + 1];
            pq.push({nextElement, listIdx, elementIdx + 1});
            maxElement = max(maxElement, nextElement);
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Vector of Pointers) : O(n * k) time and O(k) space
class Solution
{
    public int[] smallestRange(List<List<Integer>> nums)
    {
        int k = nums.size();
        int[] pointers = new int[k];
        int[] ans = {-100000, 100000};

        while (true)
        {
            int minElement = Integer.MAX_VALUE, maxElement = Integer.MIN_VALUE, minElListIdx = 0;

            for (int i = 0; i < k; i++)
            {
                int listIdx = i;
                int elementIdx = pointers[i];
                int element = nums.get(listIdx).get(elementIdx);

                // Update the minimum element and the list index
                if (element < minElement)
                {
                    minElement = element;
                    minElListIdx = listIdx;
                }

                // Update the maximum element
                maxElement = Math.max(maxElement, element);
            }

            // Update the answer
            if (maxElement - minElement < ans[1] - ans[0])
            {
                ans[0] = minElement;
                ans[1] = maxElement;
            }

            // Break if any list is exhausted
            int nextIdx = pointers[minElListIdx] + 1;

            if (nextIdx == nums.get(minElListIdx).size())
                break;

            pointers[minElListIdx] = nextIdx;
        }
        return ans;
    }
}

// Way - II (Priority Queue [Min Heap]) : O(n * logk) time and O(k) space
class Solution
{
    public int[] smallestRange(List<List<Integer>> nums)
    {
        int k = nums.size();
        int[] ans = {-100000, 100000};
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)->a[0] - b[0]);

        // Insert the first element of each list into the min heap and find the maximum element
        int maxElement = Integer.MIN_VALUE;
        for (int i = 0; i < k; i++)
        {
            pq.offer(new int[]{nums.get(i).get(0), i, 0});
            maxElement = Math.max(maxElement, nums.get(i).get(0));
        }

        while (true)
        {
            int[] top = pq.poll();
            int minElement = top[0], listIdx = top[1], elementIdx = top[2];

            // Update the answer
            if (maxElement - minElement < ans[1] - ans[0])
            {
                ans[0] = minElement;
                ans[1] = maxElement;
            }

            // Break if any list is exhausted
            if (elementIdx + 1 == nums.get(listIdx).size())
                break;
                
            int nextElement = nums.get(listIdx).get(elementIdx + 1);
            pq.offer(new int[]{nextElement, listIdx, elementIdx + 1});
            maxElement = Math.max(maxElement, nextElement);
        }
        return ans;
    }
}