// Leetcode : https://leetcode.com/problems/stone-game-ii/description/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (DP) : O(n^3) time and O(n^2) space
class Solution
{
    int n;
    int t[2][101][101];
    int stonesOfAlice(vector<int> &piles, int player, int i, int M)
    {
        if (i >= n)
            return 0;

        if (t[player][i][M] != -1)
            return t[player][i][M];

        // If Alice, we are playing for maximum, so initialize with -1, otherwise for B require minimum, initialize with greater value
        int ans = (player == 1) ? -1 : INT_MAX;
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++)
        {
            stones += piles[i + x - 1];
            // If Alice, add the stones and play for Bob
            if (player == 1)
                ans = max(ans, stones + stonesOfAlice(piles, 0, i + x, max(M, x)));
            // Otherwise get the minimum stones for Bob play for Alice
            else
                ans = min(ans, stonesOfAlice(piles, 1, i + x, max(M, x)));
        }
        return t[player][i][M] = ans;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return stonesOfAlice(piles, 1, 0, 1);
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (DP) : O(n^3) time and O(n^2) space
class Solution
{
    int n;
    int[][][] t = new int[2][101][101];
    public int stoneGameII(int[] piles)
    {
        n = piles.length;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 101; j++)
                Arrays.fill(t[i][j], -1);
        return stonesOfAlice(piles, 1, 0, 1);
    }
    private int stonesOfAlice(int[] piles, int player, int i, int M)
    {
        if (i >= n)
            return 0;
        if (t[player][i][M] != -1)
            return t[player][i][M];
        int ans = (player == 1) ? -1 : Integer.MAX_VALUE;
        int stones = 0;
        for (int x = 1; x <= Math.min(2 * M, n - i); x++)
        {
            stones += piles[i + x - 1];
            if (player == 1)
                ans = Math.max(ans, stones + stonesOfAlice(piles, 0, i + x, Math.max(M, x)));
            else
                ans = Math.min(ans, stonesOfAlice(piles, 1, i + x, Math.max(M, x)));
        }
        return t[player][i][M] = ans;
    }
}