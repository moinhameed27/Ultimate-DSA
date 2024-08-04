// Leetcode : https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/

// Way - I (Two Pointers)
/*
1. Count the flips for rows and columns.
2. For each row, check the number of flips required to make it palindrome.
3. For each column, check the number of flips required to make it palindrome.
4. Return the minimum of rowFlips and colFlips.
- To check the palindrome, we can use two pointers approach.
- Compare the start and end elements and move the pointers towards each other.
*/
class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int rowFlips = 0, colFlips = 0;

        for (int i = 0; i < m; i++)
        {
            int flips = 0;
            for (int j = 0; j < n / 2; j++)
            {
                if (grid[i][j] != grid[i][n - j - 1])
                    flips++;
            }
            rowFlips += flips;
        }

        for (int j = 0; j < n; j++)
        {
            int flips = 0;
            for (int i = 0; i < m / 2; i++)
            {
                if (grid[i][j] != grid[m - i - 1][j])
                    flips++;
            }
            colFlips += flips;
        }
        return min(rowFlips, colFlips);
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int rowFlips = 0, colFlips = 0;

        for (int i = 0; i < m; i++)
        {
            int a = 0, b = n - 1;
            while (a < b)
            {
                if (grid[i][a++] != grid[i][b--])
                    rowFlips++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            int a = 0, b = m - 1;
            while (a < b)
            {
                if (grid[a++][j] != grid[b--][j])
                    colFlips++;
            }
        }
        return min(rowFlips, colFlips);
    }
};