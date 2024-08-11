// Leetcode : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

/*
1. Maximum days cannot be more than 2.
2. If there are 0 islands or more than 1 island, then the answer is 0.
3. Convert every 1 into 0 and check the number of islands.
4. If after conversion, islands become more than 2 or 0, then the answer is 1.
5. Otherwise, the answer is 2.
*/
// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Queue/Stack)
class Solution
{
public:
    int ROWS, COLS;
    vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool insideBounds(int x, int y) { return x >= 0 && x < ROWS && y >= 0 && y < COLS; }

    // Search for given island
    void search(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        queue<pair<int, int>> pq;
        pq.push({i, j});

        while (!pq.empty())
        {
            int x = pq.front().first, y = pq.front().second;
            pq.pop();

            for (auto &d : DIRECTIONS)
            {
                int newX = x + d.first, newY = y + d.second;
                if (insideBounds(newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    pq.push({newX, newY});
                }
            }
        }
    }

    // Count the number of islands
    int numIslands(vector<vector<int>> &grid)
    {
        int islands = 0;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    islands++;
                    visited[i][j] = true;
                    search(grid, i, j, visited);
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>> &grid)
    {
        ROWS = grid.size(), COLS = grid[0].size();
        int islands = numIslands(grid);

        if (islands == 0 || islands > 1)
            return 0;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    islands = numIslands(grid);
                    if (islands > 1 || islands == 0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Queue/Stack)
class Solution
{
    int ROWS, COLS;
    int[][] DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public boolean insideBounds(int x, int y)
    {
        return x >= 0 && x < ROWS && y >= 0 && y < COLS;
    }

    // Search for given island
public void search(int[][] grid, int i, int j, boolean[][] visited)
    {
        Queue<int[]> pq = new LinkedList<>();
        pq.offer(new int[]{i, j});

        while (!pq.isEmpty())
        {
            int[] point = pq.poll();
            int x = point[0], y = point[1];

            for (int[] d : DIRECTIONS)
            {
                int newX = x + d[0], newY = y + d[1];
                if (insideBounds(newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    pq.offer(new int[]{newX, newY});
                }
            }
        }
    }

    // Count the number of islands
public int numIslands(int[][] grid)
    {
        int islands = 0;
        boolean[][] visited = new boolean[ROWS][COLS];
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    islands++;
                    visited[i][j] = true;
                    search(grid, i, j, visited);
                }
            }
        }
        return islands;
    }

public int minDays(int[][] grid)
    {
        ROWS = grid.length;
        COLS = grid[0].length;
        int islands = numIslands(grid);

        if (islands == 0 || islands > 1)
            return 0;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    islands = numIslands(grid);
                    if (islands > 1 || islands == 0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
