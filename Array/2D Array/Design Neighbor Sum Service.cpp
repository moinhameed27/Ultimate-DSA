// Leetcode : https://leetcode.com/problems/design-neighbor-sum-service/description/

#include <vector>
using namespace std;

class neighborSum
{
    vector<vector<int>> mat;
    int n;

    pair<int, int> findIndexOfValue(int value)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == value)
                    return {i, j};
            }
        }
        return {-1, -1};
    }

public:
    neighborSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        mat = grid;
    }

    int adjacentSum(int value)
    {
        pair<int, int> xy = findIndexOfValue(value);
        int x = xy.first, y = xy.second;
        int sum = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto &p : dir)
        {
            int newX = x + p.first, newY = y + p.second;
            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
                sum += mat[newX][newY];
        }
        return sum;
    }

    int diagonalSum(int value)
    {
        pair<int, int> xy = findIndexOfValue(value);
        int x = xy.first, y = xy.second;
        int sum = 0;
        vector<pair<int, int>> dir = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
        for (auto &p : dir)
        {
            int newX = x + p.first, newY = y + p.second;
            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
                sum += mat[newX][newY];
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
