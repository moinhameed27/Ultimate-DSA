// Leetcode : https://leetcode.com/problems/queries-on-a-permutation-with-key/description/

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    void copyValues(vector<int> &p1, int val)
    {
        vector<int> p2 = p1;
        p1[0] = val;
        int a = 1;
        for (int i = 0; i < p1.size(); i++)
        {
            if (p2[i] != val)
                p1[a++] = p2[i];
        }
    }

public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        int n = queries.size();
        vector<int> permutation(m);
        vector<int> ans(n);
        // Making a permutation array of size m
        for (int i = 0; i < m; i++)
            permutation[i] = i + 1;
        for (int i = 0; i < n; i++)
        {
            int curr = queries[i];
            // Finding the index of current query and storing in the answer
            for (int j = 0; j < m; j++)
            {
                if (permutation[j] == curr)
                {
                    ans[i] = j;
                    break;
                }
            }
            // Sending the current query to the front of the permutation array
            copyValues(permutation, curr);
        }
        return ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public
    int[] processQueries(int[] queries, int m)
    {
        int n = queries.length;
        int[] permutation = new int[m];
        int[] ans = new int[n];
        for (int i = 0; i < m; i++)
            permutation[i] = i + 1;
        for (int i = 0; i < n; i++)
        {
            int curr = queries[i];
            for (int j = 0; j < m; j++)
            {
                if (permutation[j] == curr)
                {
                    ans[i] = j;
                    break;
                }
            }
            copyValues(permutation, curr);
        }
        return ans;
    }

    void copyValues(int[] p1, int val)
    {
        int[] p2 = p1.clone();
        p1[0] = val;
        int a = 1;
        for (int i = 0; i < p1.length; i++)
        {
            if (p2[i] != val)
                p1[a++] = p2[i];
        }
    }
}