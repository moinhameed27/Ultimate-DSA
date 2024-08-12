// Leetcode : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

// C++----------------------------------------------------------------------------------------------------------------------------
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// Way - I (Min Heap)
class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int i : nums)
            addToQueue(i);
    }

    int add(int val)
    {
        addToQueue(val);
        return pq.top();
    }
    void addToQueue(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Min Heap)
class KthLargest
{
    int K;
    PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
public
    KthLargest(int k, int[] nums)
    {
        K = k;
        for (int i : nums)
            addToQueue(i);
    }

public
    int add(int val)
    {
        addToQueue(val);
        return pq.peek();
    }
public
    void addToQueue(int val)
    {
        pq.add(val);
        if (pq.size() > K)
            pq.remove();
    }
}
