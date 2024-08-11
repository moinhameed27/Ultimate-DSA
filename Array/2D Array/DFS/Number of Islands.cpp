// Leetcode : https://leetcode.com/problems/number-of-islands/description/

// Way - I
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '7'; // Mark as visited
                    queue<pair<int, int>> pq;
                    pq.push({i, j});
                    while (!pq.empty())
                    {
                        int x = pq.front().first, y = pq.front().second;
                        pq.pop();
                        // Check bottom
                        if (x + 1 < m && grid[x + 1][y] == '1')
                        {
                            grid[x + 1][y] = '7';
                            pq.push({x + 1, y});
                        }
                        // Check top
                        if (x - 1 >= 0 && grid[x - 1][y] == '1')
                        {
                            grid[x - 1][y] = '7';
                            pq.push({x - 1, y});
                        }
                        // Check right
                        if (y + 1 < n && grid[x][y + 1] == '1')
                        {
                            grid[x][y + 1] = '7';
                            pq.push({x, y + 1});
                        }
                        // Check left
                        if (y - 1 >= 0 && grid[x][y - 1] == '1')
                        {
                            grid[x][y - 1] = '7';
                            pq.push({x, y - 1});
                        }
                    }
                }
            }
        }
        return islands;
    }
};

// Way - II
class Solution
{
    int m, n;
    bool insideBounds(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
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
                    grid[i][j] = '7';   // Mark as visited
                    queue<pair<int, int>> pq;
                    pq.push({i, j});
                    // Horizontal and Vertical directions
                    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    while (!pq.empty())
                    {
                        int x = pq.front().first, y = pq.front().second;
                        pq.pop();
                        // Check for all neighbours
                        for (auto &d : directions)
                        {
                            int newX = x + d.first, newY = y + d.second;
                            if (insideBounds(newX, newY) && grid[newX][newY] == '1')
                            {
                                grid[newX][newY] = '7';
                                pq.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
