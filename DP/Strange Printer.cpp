// Leetcode : https://leetcode.com/problems/strange-printer/description/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion + Memiozation) : O(n^3) time and O(n^2) space
class Solution
{
    int t[101][101];
    int solve(string &s, int left, int right)
    {
        if (left == right)  // Only one character
            return 1;
        if (left > right)   // No character
            return 0;

        if (t[left][right] != -1)
            return t[left][right];
        
        // Skip same consecutive characters
        int i = left + 1;
        while (i <= right && s[i] == s[left])
            i++;

        // If current range is having same characters
        if (i == right + 1)
            return t[left][right] = 1;

        // Basic recursion call
        int basic = 1 + solve(s, i, right);
        int greedy = INT_MAX;
        for (int j = i; j <= right; j++)
        {
            // Check in the range with every character, and get the minimum
            if (s[j] == s[left])
            {
                // Recursion call for left and right part
                int curr = solve(s, i, j - 1) + solve(s, j, right);
                greedy = min(greedy, curr);
            }
        }
        // Return the minimum of basic and greedy
        return t[left][right] = min(basic, greedy);
    }

public:
    int strangePrinter(string s)
    {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n - 1);
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion + Memiozation) : O(n^3) time and O(n^2) space
class Solution 
{
    int[][] t;
    public int strangePrinter(String s) 
    {
        int n = s.length();
        t = new int[n][n];
        for(int i = 0; i < n; i++)
            Arrays.fill(t[i], -1);
        return solve(s, 0, n - 1);
    }
    
    private int solve(String s, int left, int right) 
    {
        if(left == right) // Only one character
            return 1;
        if(left > right) // No character
            return 0;
        
        if(t[left][right] != -1)
            return t[left][right];
        
        // Skip same consecutive characters
        int i = left + 1;
        while(i <= right && s.charAt(i) == s.charAt(left))
            i++;
        
        // If current range is having same characters
        if(i == right + 1)
            return t[left][right] = 1;
        
        // Basic recursion call
        int basic = 1 + solve(s, i, right);
        int greedy = Integer.MAX_VALUE;
        for(int j = i; j <= right; j++) 
        {
            // Check in the range with every character, and get the minimum
            if(s.charAt(j) == s.charAt(left)) 
            {
                // Recursion call for left and right part
                int curr = solve(s, i, j - 1) + solve(s, j, right);
                greedy = Math.min(greedy, curr);
            }
        }
        // Return the minimum of basic and greedy
        return t[left][right] = Math.min(basic, greedy);
    }
}