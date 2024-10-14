// Leetcode : https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        int n = nums.size();
        // Find maximum element everytime and perform operation
        for (int i = 0; i < k; i++)
        {
            auto it = max_element(nums.begin(), nums.end());
            int maxElement = *it;
            int maxElementIdx = distance(nums.begin(), it);
            ans += maxElement;
            nums[maxElementIdx] = ceil(nums[maxElementIdx] / 3.0);
        }
        return ans;
    }
};

// Way - II (Priority Queue [Max Heap]) : O(n * logn) time and O(n) space
/* Push all elements into Max Heap and perform operations on top k elements */
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        int n = nums.size();
        priority_queue<int> pq;
        for (int num : nums)
            pq.push(num);

        for (int i = 0; i < k; i++)
        {
            int top = pq.top();
            ans += top;
            pq.pop();
            top = ceil(top / 3.0);
            pq.push(top);
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space
class Solution
{
    public long maxKelements(int[] nums, int k)
    {
        long ans = 0;
        int n = nums.length;
        // Find maximum element everytime and perform operation
        for (int i = 0; i < k; i++)
        {
            int maxElementIdx = 0;
            for (int j = 1; j < n; j++)
            {
                if (nums[j] > nums[maxElementIdx])
                    maxElementIdx = j;
            }
            ans += nums[maxElementIdx];
            nums[maxElementIdx] = (int)Math.ceil(nums[maxElementIdx] / 3.0);
        }
        return ans;
    }
}

// Way - II (Priority Queue [Max Heap]) : O(n * logn) time and O(n) space
/* Push all elements into Max Heap and perform operations on top k elements */
class Solution
{
    public long maxKelements(int[] nums, int k)
    {
        long ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : nums)
            pq.add(num);

        for (int i = 0; i < k; i++)
        {
            int top = pq.poll();
            ans += top;
            top = (int)Math.ceil(top / 3.0);
            pq.add(top);
        }
        return ans;
    }
}