// Leetcode : https://leetcode.com/problems/predict-the-winner/description/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (DP) : O(n^2) time and O(1) Space
class Solution
{
    int t[21][21];
    int solve(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return 0;
        if (left == right)
            return nums[left];

        if (t[left][right] != -1)
            return t[left][right];

        // Either Player1 chose left or right, then we'll want Player 2 to choose the minimum of the two options
        // - (left + 2) both chose left, (left + 1, right - 1) Player1 chose left and Player chose right
        int chooseLeft = nums[left] + min(solve(nums, left + 2, right), solve(nums, left + 1, right - 1));
        // - (right + 2) both chose right, (left + 1, right - 1) Player1 chose right and Player chose left
        int chooseRight = nums[right] + min(solve(nums, left, right - 2), solve(nums, left + 1, right - 1));

        return t[left][right] = max(chooseLeft, chooseRight);
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int playerOne = solve(nums, 0, n - 1);
        int playerTwo = total - playerOne;
        return playerOne >= playerTwo;
    }
};

// Way - II (Difference of Score between 2 Players)
class Solution
{
    int t[21][21];
    int solve(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return 0;
        if (left == right)
            return nums[left];

        if (t[left][right] != -1)
            return t[left][right];

        int chooseLeft = nums[left] - solve(nums, left + 1, right);
        int chooseRight = nums[right] - solve(nums, left, right - 1);

        return t[left][right] = max(chooseLeft, chooseRight);
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n - 1) >= 0;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (DP) : O(n^2) time and O(1) Space
class Solution 
{
    int[][] t = new int[21][21];
    private int solve(int[] nums, int left, int right) 
    {
        if (left > right) return 0;
        if (left == right) return nums[left];
        
        if (t[left][right] != -1) return t[left][right];
        
        int chooseLeft = nums[left] + Math.min(solve(nums, left + 2, right), solve(nums, left + 1, right - 1));
        int chooseRight = nums[right] + Math.min(solve(nums, left, right - 2), solve(nums, left + 1, right - 1));
        
        return t[left][right] = Math.max(chooseLeft, chooseRight);
    }
    
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < 21; i++) 
            Arrays.fill(t[i], -1);
        int total = 0;
        for (int num : nums) 
            total += num;
        int playerOne = solve(nums, 0, n - 1);
        int playerTwo = total - playerOne;
        return playerOne >= playerTwo;
    }
}

// Way - II (Difference of Score between 2 Players)
class Solution 
{
    int[][] t = new int[21][21];
    private int solve(int[] nums, int left, int right) 
    {
        if (left > right) return 0;
        if (left == right) return nums[left];
        
        if (t[left][right] != -1) return t[left][right];
        
        int chooseLeft = nums[left] - solve(nums, left + 1, right);
        int chooseRight = nums[right] - solve(nums, left, right - 1);
        
        return t[left][right] = Math.max(chooseLeft, chooseRight);
    }
    
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < 21; i++) 
            Arrays.fill(t[i], -1);
        return solve(nums, 0, n - 1) >= 0;
    }
}