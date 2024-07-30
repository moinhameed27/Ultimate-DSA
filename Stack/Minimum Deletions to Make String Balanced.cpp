// LeetCode : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

// Way - I (Stack) - O(n) time and O(n) space
/* For every 'a', check if top of stack is b, means 'ba' is forming, increase the count */
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size(), ans = 0;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && s[i] == 'a' && st.top() == 'b')
            {
                ans++;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        return ans;
    }
};

// Way - II (Counting) - O(3*n) time and O(2*n) space
/*
1. For every element, remove all b from it's left and every a from it's right, the resultant string will be valid.
2. Count the smallest number of removals required.
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> leftB(n, 0);
        vector<int> rightA(n, 0);
        int countB = 0, countA = 0;
        // Counting b's on the left for every index
        for (int i = 0; i < n; i++)
        {
            leftB[i] = countB;
            if (s[i] == 'b')
                countB++;
        }

        // Counting a's on the right for every index
        for (int i = n - 1; i >= 0; i--)
        {
            rightA[i] = countA;
            if (s[i] == 'a')
                countA++;
        }

        // Find the minimum number of removals required
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, leftB[i] + rightA[i]);

        return ans;
    }
};

// Way - III (Counting) - O(2*n) time and O(n) space
/*
1. Count number of a's on the right for every index.
2. Count number of b's on the flow for every index.
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> rightA(n, 0);
        int countB = 0, countA = 0;

        // Count number of a's on the right for every index.
        for (int i = n - 1; i >= 0; i--)
        {
            rightA[i] = countA;
            if (s[i] == 'a')
                countA++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, countB + rightA[i]);
            // If current index is b, increase the count of b's on the left
            if (s[i] == 'b')
                countB++;
        }

        return ans;
    }
};

// Way - IV (Counting) - O(2*n) time and O(1) space
/*
1. Count total number of a's in the string.
2. Count number of b's on the flow for every index.
3. For every index, calculate the number of a's on the right and b's on the left.
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> rightA(n, 0);
        int countB = 0, countA = 0;

        // Total number of a's in the string
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'a')
                countA++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            // If current element is a, remove the count of a's on the right of current index
            if (s[i] == 'a')
                countA--;
            ans = min(ans, countB + countA);
            // If current index is b, increase the count of b's on the left
            if (s[i] == 'b')
                countB++;
        }

        return ans;
    }
};