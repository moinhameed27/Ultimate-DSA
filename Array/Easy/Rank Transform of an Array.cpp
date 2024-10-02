// Leetcode : https://leetcode.com/problems/rank-transform-of-an-array/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Vector of Pair[val, idx])
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> arrIdx(n);
        // Store the value and index of the array
        for (int i = 0; i < n; i++)
            arrIdx[i] = {arr[i], i};

        sort(arrIdx.begin(), arrIdx.end());
        vector<int> ranks(n);
        int prev = INT_MIN, rank = 0;
        // Assign the rank to the array
        for (auto &[x, i] : arrIdx)
        {
            if (x > prev) // Duplicates have same rank
                rank++;
            ranks[i] = rank;
            prev = x;
        }
        return ranks;
    }
};

// Way - II (Prioriy Queue [Min Heap])
#define pii pair<int, int>
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // Store the value and index of the array
        for (int i = 0; i < n; i++)
            pq.push({arr[i], i});

        int rank = 0, prev = INT_MIN;

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();

            // Duplicates have same rank
            if (top.first > prev)
                rank++;

            arr[top.second] = rank;
            prev = top.first;
        }

        return arr;
    }
};

// Way - III (HashMap)
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp; // {value, rank}
        vector<int> temp(arr);

        sort(temp.begin(), temp.end());

        int rank = 1;
        for (int i = 0; i < n; i++)
        {
            // Assign ranks to the unique elements only
            if (mp.find(temp[i]) == mp.end())
                mp[temp[i]] = rank++;
        }

        for (int i = 0; i < n; i++)
            arr[i] = mp[arr[i]];

        return arr;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Array of Pair[val, idx])
class Solution 
{
    public int[] arrayRankTransform(int[] arr) 
    {
        int n = arr.length;
        int[][] arrIdx = new int[n][2];

        // Store the value and index of the array
        for (int i = 0; i < n; i++)
            arrIdx[i] = new int[]{arr[i], i};

        Arrays.sort(arrIdx, (a, b) -> a[0] - b[0]);
        int[] ranks = new int[n];
        int prev = Integer.MIN_VALUE, rank = 0;

        // Assign the rank to the array
        for (int[] x : arrIdx) 
        {
            if (x[0] > prev) // Duplicates have same rank
                rank++;
            ranks[x[1]] = rank;
            prev = x[0];
        }
        return ranks;
    }
}

// Way - II (Prioriy Queue [Min Heap])
class Solution 
{
    public int[] arrayRankTransform(int[] arr) 
    {
        int n = arr.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Store the value and index of the array
        for (int i = 0; i < n; i++)
            pq.add(new int[]{arr[i], i});

        int rank = 0, prev = Integer.MIN_VALUE;

        while (!pq.isEmpty()) 
        {
            int[] top = pq.poll();

            // Duplicates have same rank
            if (top[0] > prev)
                rank++;

            arr[top[1]] = rank;
            prev = top[0];
        }

        return arr;
    }
}

// Way - III (HashMap)
class Solution 
{
    public int[] arrayRankTransform(int[] arr) 
    {
        int n = arr.length;
        HashMap<Integer, Integer> mp = new HashMap<>(); // {value, rank}
        int[] temp = arr.clone();

        Arrays.sort(temp);

        int rank = 1;
        for (int i = 0; i < n; i++) 
        {
            // Assign ranks to the unique elements only
            if (!mp.containsKey(temp[i]))
                mp.put(temp[i], rank++);
        }

        for (int i = 0; i < n; i++)
            arr[i] = mp.get(arr[i]);

        return arr;
    }
}