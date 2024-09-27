// GFG : https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sliding Window at every k sized subarray]) [TLE]
class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        int maxElement = INT_MIN, n = arr.size();
        vector<int> ans;
        int i = 0, j = 0;
        while (j < n)
        {
            maxElement = max(maxElement, arr[j]);
            // If subarray size is k, push the max element in ans and slide the window along with updating the maxElement
            if (j - i + 1 == k)
            {
                ans.push_back(maxElement);
                maxElement = INT_MIN;
                // One element is removed from the window, so update the maxElement
                for (int k = i + 1; k <= j; k++)
                    maxElement = max(maxElement, arr[k]);
                i++;
            }
            j++;
        }
        return ans;
    }
};

// Way - II (Similar to Way - I) [TLE]
class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++)
        {
            int maxElement = INT_MIN;
            for (int j = 0; j < k; j++)
                maxElement = max(maxElement, arr[i + j]);
            ans.push_back(maxElement);
        }
        return ans;
    }
};

// Way - III (Priority Queue + Sliding Window)
class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        int i = 0, j = 0;
        priority_queue<pair<int, int>> pq;
        while (j < n)
        {
            pq.push({arr[j], j});
            // If k sized window is formed, push the max element in ans and slide the window
            if (pq.size() >= k)
            {
                // Ensure that the top element of the pq is within the window
                while (!pq.empty() && pq.top().second < i)
                    pq.pop();
                ans.push_back(pq.top().first);
                i++;
            }
            j++;
        }
        return ans;
    }
};

// Way - IV (Deque + Sliding Window)
/* Ensure that the front is inside the window and back element is greatest in the window. */
class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        int i = 0, j = 0;
        deque<int> dq; // Store the index of the elements
        for (int i = 0; i < n; i++)
        {
            // Ensure that the front is inside the window
            while (!dq.empty() && dq.front() <= (i - k))
                dq.pop_front();
            // Ensure that the back element is greatest in the window
            while (!dq.empty() && arr[i] > arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            // If k sized window is formed, push the max element in ans
            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sliding Window at every k sized subarray]) [TLE]
class Solution
{
    public ArrayList<Integer> max_of_subarrays(int k, int arr[])
    {
        int maxElement = Integer.MIN_VALUE, n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0, j = 0;
        while (j < n)
        {
            maxElement = Math.max(maxElement, arr[j]);
            // If subarray size is k, push the max element in ans and slide the window along with updating the maxElement
            if (j - i + 1 == k)
            {
                ans.add(maxElement);
                maxElement = Integer.MIN_VALUE;
                // One element is removed from the window, so update the maxElement
                for (int l = i + 1; l <= j; l++)
                    maxElement = Math.max(maxElement, arr[l]);
                i++;
            }
            j++;
        }
        return ans;
    }
}

// Way - II (Similar to Way - I) [TLE]
class Solution
{
    public ArrayList<Integer> max_of_subarrays(int k, int arr[])
    {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i <= n - k; i++)
        {
            int maxElement = Integer.MIN_VALUE;
            for (int j = 0; j < k; j++)
                maxElement = Math.max(maxElement, arr[i + j]);
            ans.add(maxElement);
        }
        return ans;
    }
}

// Way - III (Priority Queue + Sliding Window)
class Pair
{
    public int value;
    public int index;

    public Pair(int value, int index)
    {
        this.value = value;
        this.index = index;
    }
}

class Solution
{
    public ArrayList<Integer> max_of_subarrays(int k, int arr[])
    {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0, j = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b)->b.value - a.value);

        while (j < n)
        {
            pq.add(new Pair(arr[j], j));
            // If a window of size k is formed, process it
            if (pq.size() >= k)
            {
                // Remove elements that are out of the current window
                while (!pq.isEmpty() && pq.peek().index < i)
                    pq.poll();

                ans.add(pq.peek().value);
                i++; // Slide the window
            }
            j++;
        }

        return ans;
    }
}

// Way - IV (Deque + Sliding Window)
class Solution
{
    public ArrayList<Integer> max_of_subarrays(int k, int arr[])
    {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0, j = 0;
        Deque<Integer> dq = new LinkedList<>();

        for (int l = 0; l < n; l++)
        {
            // Ensure that the front is inside the window
            while (!dq.isEmpty() && dq.peekFirst() <= (l - k))
                dq.pollFirst();
            // Ensure that the back element is greatest in the window
            while (!dq.isEmpty() && arr[l] > arr[dq.peekLast()])
                dq.pollLast();
            dq.addLast(l);
            // If k sized window is formed, push the max element in ans
            if (l >= k - 1)
                ans.add(arr[dq.peekFirst()]);
        }

        return ans;
    }
}