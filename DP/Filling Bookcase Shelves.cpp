// LeetCode : https://leetcode.com/problems/filling-bookcase-shelves

// Recursion + Memoization
class Solution
{
public:
    int n, WIDTH;
    int t[1001][1001];

    int solve(vector<vector<int>> &books, int i, int remainW, int maxHeight)
    {
        // If all array is traversed
        if (i >= n)
            return maxHeight;

        // If result is also saved, return from here
        if (t[i][remainW] != -1)
            return t[i][remainW];

        int bookW = books[i][0], bookH = books[i][1];
        int keep = INT_MAX, skip = INT_MIN;

        // Option to keep the book in current shelf
        if (bookW <= remainW)
            keep = solve(books, i + 1, remainW - bookW, max(maxHeight, bookH));

        // Skip the book and move to next shelf with current height
        skip = maxHeight + solve(books, i + 1, WIDTH - bookW, bookH);
        
        // Answer will be minimum of both options
        return t[i][remainW] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        memset(t, -1, sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;
        int remainW = shelfWidth;
        return solve(books, 0, remainW, 0);
    }
};