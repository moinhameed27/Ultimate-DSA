// GFG : https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long> &arr)
    {
        long long sum = 0, a, b, rope;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : arr)
            pq.push(i);

        while (pq.size() > 1)
        {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();

            rope = a + b;
            sum += rope;
            pq.push(rope);
        }

        return sum;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    // Function to return the minimum cost of connecting the ropes.
    public long minCost(long[] arr) 
    {
        long sum = 0, a, b, rope;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (long i : arr)
            pq.add(i);

        while (pq.size() > 1) 
        {
            a = pq.poll();
            b = pq.poll();

            rope = a + b;
            sum += rope;
            pq.add(rope);
        }
        return sum;
    }
}