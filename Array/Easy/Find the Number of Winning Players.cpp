// Leetcode : https://leetcode.com/problems/find-the-number-of-winning-players/description/

// Way - I (Vector)
/* Number of players are only 10, so vector can also be used. */
class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        vector<vector<int>> v(n, vector<int>(11, 0));
        for (int i = 0; i < pick.size(); i++)
        {
            int player = pick[i][0];
            int ball = pick[i][1];
            v[player][ball]++;
        }

        int winners = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 10; j++)
            {
                if (v[i][j] > i)
                {
                    winners++;
                    break;
                }
            }
        }
        return winners;
    }
};

// Way - II (Hashmap)
class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        unordered_map<int, unordered_map<int, int>> mp;

        // Storing the count of balls picked by each player
        for (auto &p : pick)
        {
            int player = p[0];
            int ball = p[1];
            mp[player][ball]++;
        }

        int winners = 0;
        // Counting the winners from 0 to n - 1
        for (int i = 0; i < n; i++)
        {
            // Counting from all the balls picked by a player, if any ball is picked more than i times, then the player is winner
            for (auto &j : mp[i])
            {
                if (j.second > i)
                {
                    winners++;
                    break;
                }
            }
        }

        return winners;
    }
};