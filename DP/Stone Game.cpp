// Leetcode : https://leetcode.com/problems/stone-game/description/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Simple Observation)
/* As both players will play optimally and Alice is starting first, so there's always a surity that Alice will won */
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};

// Way - II (DP) : O(n^2) time and O(n^2) space
class Solution
{
    int t[501][501];
    int solve(vector<int> &piles, int left, int right)
    {
        if (left > right)
            return 0;
        // If both sides, are equal return any of them
        if (left == right)
            return piles[left];

        if (t[left][right] != -1)
            return t[left][right];

        // Either Alice chose left or right, then we'll want Bob to choose the minimum of the two options
        // - (left + 2) both chose left, (left + 1, right - 1) Alice chose left and Bob chose right
        int chooseLeft = piles[left] + min(solve(piles, left + 2, right), solve(piles, left + 1, right - 1));
        // - (right + 2) both chose right, (left + 1, right - 1) Alice chose right and Bob chose left
        int chooseRight = piles[right] + min(solve(piles, left, right - 2), solve(piles, left + 1, right - 1));

        // Then chose optimally for Alice
        return t[left][right] = max(chooseLeft, chooseRight);
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        memset(t, -1, sizeof(t));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = solve(piles, 0, n - 1);
        return aliceScore > (sum / 2);
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Simple Observation)
class Solution
{
public
    boolean stoneGame(int[] piles)
    {
        return true;
    }
}

// Way - II (DP) : O(n^2) time and O(n^2) space
class Solution
{
    int[][] t = new int[501][501];

    private int solve(int[] piles, int left, int right)
    {
        if (left > right)
            return 0;
        // If both sides, are equal return any of them
        if (left == right)
            return piles[left];

        if (t[left][right] != -1)
            return t[left][right];

        // Either Alice chose left or right, then we'll want Bob to choose the minimum of the two options
        // - (left + 2) both chose left, (left + 1, right - 1) Alice chose left and Bob chose right
        int chooseLeft = piles[left] + Math.min(solve(piles, left + 2, right), solve(piles, left + 1, right - 1));
        // - (right + 2) both chose right, (left + 1, right - 1) Alice chose right and Bob chose left
        int chooseRight = piles[right] + Math.min(solve(piles, left, right - 2), solve(piles, left + 1, right - 1));

        // Then chose optimally for Alice
        return t[left][right] = Math.max(chooseLeft, chooseRight);
    }

    public boolean stoneGame(int[] piles)
    {
        int n = piles.length;
        for (int i = 0; i < 501; i++)
            Arrays.fill(t[i], -1);
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += piles[i];
        int aliceScore = solve(piles, 0, n - 1);
        return aliceScore > (sum / 2);
    }
}