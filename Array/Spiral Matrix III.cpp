// Leetcode : https://leetcode.com/problems/spiral-matrix-iii/description/

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    // directions array to move in 4 directions : East, South, West, North
    vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> ans;
        int steps = 0, currDirection = 0;
        ans.push_back({rStart, cStart});
        while (ans.size() < rows * cols)
        {
            // After every 2 directions, increase the steps
            if (currDirection == 0 || currDirection == 2)
                steps++;
            for (int i = 0; i < steps; i++)
            {
                rStart += DIRECTIONS[currDirection][0];
                cStart += DIRECTIONS[currDirection][1];
                // If inside the grid, add the cell to the ans
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    ans.push_back({rStart, cStart});
            }
            // Change the direction
            currDirection = (currDirection + 1) % 4;
        }
        return ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        List<int[]> ans = new ArrayList<>();
        int steps = 0, currDirection = 0;
        ans.add(new int[]{rStart, cStart});
        while (ans.size() < rows * cols)
        {
            if (currDirection == 0 || currDirection == 2)
                steps++;
            for (int i = 0; i < steps; i++)
            {
                rStart += directions[currDirection][0];
                cStart += directions[currDirection][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                {
                    ans.add(new int[]{rStart, cStart});
                }
            }
            currDirection = (currDirection + 1) % 4;
        }
        return ans.toArray(new int[rows * cols][2]);
    }
}