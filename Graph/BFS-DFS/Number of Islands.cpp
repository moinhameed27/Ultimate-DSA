// Leetcode : https://leetcode.com/problems/number-of-islands/

// GFG : https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

// ************************************************************{Leetcode}************************************************************
// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (DFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4 Directions
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;
        grid[i][j] = '2';

        for (auto &dir : directions)
        {
            int x = i + dir.first, y = j + dir.second;
            dfs(grid, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};

// Way - II (BFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4 Directions
    bool insideBounds(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            // Search for Neighbours
            for (auto &d : directions)
            {
                int newX = x + d.first, newY = y + d.second;
                if (insideBounds(newX, newY) && grid[newX][newY] == '1')
                {
                    grid[newX][newY] = '2';
                    q.push({newX, newY});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '2';
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (DFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4 Directions

    void dfs(char[][] grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;
        grid[i][j] = '2';

        for (int[] dir : directions)
        {
            int x = i + dir[0], y = j + dir[1];
            dfs(grid, x, y);
        }
    }

    public int numIslands(char[][] grid)
    {
        m = grid.length;
        n = grid[0].length;
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
}

// Way - II (BFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4 Directions

    boolean insideBounds(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void bfs(char[][] grid, int i, int j)
    {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        while (!q.isEmpty())
        {
            int x = q.peek()[0], y = q.peek()[1];
            q.poll();
            // Search for Neighbours
            for (int[] d : directions)
            {
                int newX = x + d[0], newY = y + d[1];
                if (insideBounds(newX, newY) && grid[newX][newY] == '1')
                {
                    grid[newX][newY] = '2';
                    q.add(new int[]{newX, newY});
                }
            }
        }
    }

    public int numIslands(char[][] grid)
    {
        m = grid.length;
        n = grid[0].length;
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '2';
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
}


// ************************************************************{GFG}************************************************************
// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (DFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                                         {-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; // 8 Directions
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;
        grid[i][j] = '2';

        for (auto &dir : directions)
        {
            int x = i + dir.first, y = j + dir.second;
            dfs(grid, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};

// Way - II (BFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                                         {-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; // 8 Directions
    bool insideBounds(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            // Search for Neighbours
            for (auto &d : directions)
            {
                int newX = x + d.first, newY = y + d.second;
                if (insideBounds(newX, newY) && grid[newX][newY] == '1')
                {
                    grid[newX][newY] = '2';
                    q.push({newX, newY});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '2';
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (DFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                          {-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; // 8 Directions

    void dfs(char[][] grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;
        grid[i][j] = '2';

        for (int[] dir : directions)
        {
            int x = i + dir[0], y = j + dir[1];
            dfs(grid, x, y);
        }
    }

    public int numIslands(char[][] grid)
    {
        m = grid.length;
        n = grid[0].length;
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
}

// Way - II (BFS) : O(m * n) time and O(m * n) space
class Solution
{
    int m, n;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                          {-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; // 8 Directions

    boolean insideBounds(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void bfs(char[][] grid, int i, int j)
    {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        while (!q.isEmpty())
        {
            int x = q.peek()[0], y = q.peek()[1];
            q.poll();
            // Search for Neighbours
            for (int[] d : directions)
            {
                int newX = x + d[0], newY = y + d[1];
                if (insideBounds(newX, newY) && grid[newX][newY] == '1')
                {
                    grid[newX][newY] = '2';
                    q.add(new int[]{newX, newY});
                }
            }
        }
    }

    public int numIslands(char[][] grid)
    {
        m = grid.length;
        n = grid[0].length;
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '2';
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
}