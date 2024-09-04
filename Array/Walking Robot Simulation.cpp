// Leetcode : https://leetcode.com/problems/walking-robot-simulation/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<string> st;
        // Storing obstacles to check if the next step is obstacle or not
        for (vector<int> &obs : obstacles)
        {
            string str = to_string(obs[0]) + "," + to_string(obs[1]);
            st.insert(str);
        }

        int x = 0, y = 0, ans = 0;
        pair<int, int> dir = {0, 1};    // Current Facing Direction, initially North

        for (int command : commands)
        {
            // Rotate 90 degree to the right
            if (command == -2)
                dir = {-dir.second, dir.first};
            // Rotate 90 degree to the left
            else if (command == -1)
                dir = {dir.second, -dir.first};
            else
            {
                for (int step = 0; step < command; step++)
                {
                    int newX = x + dir.first, newY = y + dir.second;

                    string newStr = to_string(newX) + "," + to_string(newY);
                    // If the next step is obstacle, break the loop
                    if (st.find(newStr) != st.end())
                        break;
                    // Otherwise, update the current position
                    x = newX, y = newY;
                }
            }
            // Update the maximum distance
            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    public int robotSim(int[] commands, int[][] obstacles)
    {
        Set<String> st = new HashSet<>();
        // Storing obstacles to check if the next step is obstacle or not
        for (int[] obs : obstacles)
            st.add(obs[0] + "," + obs[1]);

        int x = 0, y = 0, ans = 0;
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;    // Current Facing Direction, initially North

        for (int command : commands)
        {
            // Rotate 90 degree to the right
            if (command == -2)
                dir = (dir + 3) % 4;
            // Rotate 90 degree to the left
            else if (command == -1)
                dir = (dir + 1) % 4;
            else
            {
                for (int step = 0; step < command; step++)
                {
                    int newX = x + dirs[dir][0], newY = y + dirs[dir][1];

                    // If the next step is obstacle, break the loop
                    if (st.contains(newX + "," + newY))
                        break;
                    // Otherwise, update the current position
                    x = newX; y = newY;
                }
            }
            // Update the maximum distance
            ans = Math.max(ans, x * x + y * y);
        }

        return ans;
    }
}