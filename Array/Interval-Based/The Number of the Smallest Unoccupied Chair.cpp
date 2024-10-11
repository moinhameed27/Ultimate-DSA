// Leetcode : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n^2) time and O(n) space
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        // Times when chairs will be freed
        vector<int> departTimes(n, -1);

        // As arrival times are distinct, reserve the target arrival time after sorting
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end());

        for (vector<int> &time : times)
        {
            int arrival = time[0], departure = time[1];
            // Check for the first available chair
            for (int i = 0; i < n; i++)
            {
                if (departTimes[i] <= arrival)
                {
                    departTimes[i] = departure;
                    if (arrival == targetArrival)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};

// Way - II (Min Heap + Sorting) : O(nlogn) time and O(n) space
class Solution
{
    typedef pair<int, int> pi;

public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        int targetArrival = times[targetFriend][0]; // As arrival times are distinct, reserve the target arrival time after sorting

        priority_queue<pi, vector<pi>, greater<pi>> usedChairs;    // {departure time, chair number}
        priority_queue<int, vector<int>, greater<int>> freeChairs; // Available chairs

        int chairNo = 0; // When a new chair is used, increment the chair number
        sort(times.begin(), times.end());

        for (int i = 0; i < n; i++)
        {
            int arrival = times[i][0], departure = times[i][1];

            // Free the chairs whose departure time is less than or equal to the current arrival time
            while (!usedChairs.empty() && usedChairs.top().first <= arrival)
            {
                freeChairs.push(usedChairs.top().second);
                usedChairs.pop();
            }

            // If no chair is free, use a new chair
            if (freeChairs.empty())
            {
                usedChairs.push({departure, chairNo});
                if (arrival == targetArrival)
                    return chairNo;
                chairNo++;
            }
            // If a chair is free, use the least chair number
            else
            {
                int leastChair = freeChairs.top();
                freeChairs.pop();
                if (arrival == targetArrival)
                    return leastChair;
                usedChairs.push({departure, leastChair});
            }
        }

        return -1;
    }
};

// Way - III (Min Heap + Sorting + Vector[Tuple]) : O(nlogn) time and O(n) space
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<tuple<int, bool, int>> events;
        // tuple : {time -> arrival/departure, flag -> true for arrival, false for departure, idx -> original index}
        // Pushing all events into the events vector
        for (int i = 0; i < n; i++)
        {
            events.push_back({times[i][0], true, i});
            events.push_back({times[i][1], false, i});
        }

        sort(events.begin(), events.end());
        // Min Heap for available chairs from 0 to n-1
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++)
            availableChairs.push(i);

        // Storging the used chairs for each friend
        vector<int> usedChairs(n);

        for (auto &event : events)
        {
            int time = get<0>(event);
            bool flag = get<1>(event);
            int idx = get<2>(event);

            // If the event is arrival
            if (flag)
            {
                int chair = availableChairs.top();
                availableChairs.pop();
                usedChairs[idx] = chair;

                if (idx == targetFriend)
                    return chair;
            }
            // If the event is departure, push the chair back to the available chairs
            else
                availableChairs.push(usedChairs[idx]);
        }
        return -1;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n^2) time and O(n) space
class Solution
{
    public int smallestChair(int[][] times, int targetFriend)
    {
        int n = times.length;
        // Times when chairs will be freed
        int[] departTimes = new int[n];
        Arrays.fill(departTimes, -1);

        // As arrival times are distinct, reserve the target arrival time after sorting
        int targetArrival = times[targetFriend][0];
        Arrays.sort(times, (a, b)->a[0] - b[0]);

        for (int[] time : times)
        {
            int arrival = time[0], departure = time[1];
            // Check for the first available chair
            for (int i = 0; i < n; i++)
            {
                if (departTimes[i] <= arrival)
                {
                    departTimes[i] = departure;
                    if (arrival == targetArrival)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
}

// Way - II (Min Heap + Sorting) : O(nlogn) time and O(n) space
class Solution
{
    public int smallestChair(int[][] times, int targetFriend)
    {
        int n = times.length;
        int targetArrival = times[targetFriend][0]; // As arrival times are distinct, reserve the target arrival time after sorting

        PriorityQueue<int[]> usedChairs = new PriorityQueue<>((a, b)->a[0] - b[0]);    // {departure time, chair number}
        PriorityQueue<Integer> freeChairs = new PriorityQueue<>(); // Available chairs

        int chairNo = 0; // When a new chair is used, increment the chair number
        Arrays.sort(times, (a, b)->a[0] - b[0]);

        for (int i = 0; i < n; i++)
        {
            int arrival = times[i][0], departure = times[i][1];

            // Free the chairs whose departure time is less than or equal to the current arrival time
            while (!usedChairs.isEmpty() && usedChairs.peek()[0] <= arrival)
            {
                freeChairs.add(usedChairs.poll()[1]);
            }

            // If no chair is free, use a new chair
            if (freeChairs.isEmpty())
            {
                usedChairs.add(new int[]{departure, chairNo});
                if (arrival == targetArrival)
                    return chairNo;
                chairNo++;
            }
            // If a chair is free, use the least chair number
            else
            {
                int leastChair = freeChairs.poll();
                if (arrival == targetArrival)
                    return leastChair;
                usedChairs.add(new int[]{departure, leastChair});
            }
        }

        return -1;
    }
}

// Way - III (Min Heap + Sorting + Vector[Tuple]) : O(nlogn) time and O(n) space
class Solution
{
    public int smallestChair(int[][] times, int targetFriend)
    {
        int n = times.length;
        List<int[]> events = new ArrayList<>();
        // tuple : {time -> arrival/departure, flag -> true for arrival, false for departure, idx -> original index}
        // Pushing all events into the events vector
        for (int i = 0; i < n; i++)
        {
            events.add(new int[]{times[i][0], 1, i});
            events.add(new int[]{times[i][1], 0, i});
        }

        Collections.sort(events, (a, b)->a[0] - b[0]);
        // Min Heap for available chairs from 0 to n-1
        PriorityQueue<Integer> availableChairs = new PriorityQueue<>();
        for (int i = 0; i < n; i++)
            availableChairs.add(i);

        // Storging the used chairs for each friend
        int[] usedChairs = new int[n];

        for (int[] event : events)
        {
            int time = event[0];
            boolean flag = event[1] == 1;
            int idx = event[2];

            // If the event is arrival
            if (flag)
            {
                int chair = availableChairs.poll();
                usedChairs[idx] = chair;

                if (idx == targetFriend)
                    return chair;
            }
            // If the event is departure, push the chair back to the available chairs
            else
                availableChairs.add(usedChairs[idx]);
        }
        return -1;
    }
}