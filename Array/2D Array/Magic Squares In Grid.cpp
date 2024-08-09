// Leetcode : https://leetcode.com/problems/magic-squares-in-grid/description/

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    bool isMagicSquare(vector<vector<int>> &grid, int r, int c)
    {
        // Check Uniqueness and range 1 - 9
        unordered_map<int, int> mp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || mp.find(num) != mp.end())
                    return false;
                else
                    mp[num] = 1;
            }
        }

        // Checking the sums
        int sum = grid[r][c] + grid[r + 1][c] + grid[r + 2][c];
        for (int i = 0; i < 3; i++)
        {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != sum || // Row Sum
                grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != sum)   // Column Sum
                return false;
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum || // Diagonal Sum
            grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)   // Anti-Diagonal Sum
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                if (isMagicSquare(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
import java.util.HashSet;

class Solution
{

private
    boolean isMagicSquare(int[][] grid, int r, int c)
    {
        // Check Uniqueness and range 1 - 9
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || set.contains(num))
                {
                    return false;
                }
                set.add(num);
            }
        }

        // Checking the sums
        int sum = grid[r][c] + grid[r + 1][c] + grid[r + 2][c];
        for (int i = 0; i < 3; i++)
        {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != sum || // Row Sum
                grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != sum)
            { // Column Sum
                return false;
            }
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum || // Diagonal Sum
            grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
        { // Anti-Diagonal Sum
            return false;
        }

        return true;
    }

public
    int numMagicSquaresInside(int[][] grid)
    {
        int m = grid.length, n = grid[0].length;
        int count = 0;
        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                if (isMagicSquare(grid, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }
}
