// Leetcode : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/* Find the instersecting points between starting and ending points. */
// Way - I (Sorting + Min Heap) : O(nlogn) time and O(n) space
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        for (vector<int> &interval : intervals)
        {
            int start = interval[0], end = interval[1];
            // If the current interval starts after the earliest ending interval, then we don't need to create a new group.
            if (!pq.empty() && start > pq.top())
                pq.pop();
            pq.push(end);
        }
        return pq.size();
    }
};

/* Find the intersecting points between sorted startTimes and endTimes. */
// Way - II (Sorting + Two Pointers) : O(nlogn) time and O(n) space
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> startTimes, endTimes;
        for (vector<int> &interval : intervals)
        {
            startTimes.push_back(interval[0]);
            endTimes.push_back(interval[1]);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int groups = 0, end = 0;
        for (int start : startTimes)
        {
            // If the current interval starts after the earliest ending interval, then we don't need to create a new group.
            if (start > endTimes[end])
                end++;
            else
                groups++;
        }
        return groups;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
/* Find the instersecting points between starting and ending points. */
// Way - I (Sorting + Min Heap) : O(nlogn) time and O(n) space
class Solution
{
    public int minGroups(int[][] intervals)
    {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Arrays.sort(intervals, (a, b)->a[0] - b[0]);
        for (int[] interval : intervals)
        {
            int start = interval[0], end = interval[1];
            // If the current interval starts after the earliest ending interval, then we don't need to create a new group.
            if (!pq.isEmpty() && start > pq.peek())
                pq.poll();
            pq.offer(end);
        }
        return pq.size();
    }
}

/* Find the intersecting points between sorted startTimes and endTimes. */
// Way - II (Sorting + Two Pointers) : O(nlogn) time and O(n) space
class Solution
{
    public int minGroups(int[][] intervals)
    {
        int n = intervals.length;
        int[] startTimes = new int[n], endTimes = new int[n];
        for (int i = 0; i < n; i++)
        {
            startTimes[i] = intervals[i][0];
            endTimes[i] = intervals[i][1];
        }
        Arrays.sort(startTimes);
        Arrays.sort(endTimes);

        int groups = 0, end = 0;
        for (int start : startTimes)
        {
            // If the current interval starts after the earliest ending interval, then we don't need to create a new group.
            if (start > endTimes[end])
                end++;
            else
                groups++;
        }
        return groups;
    }
}