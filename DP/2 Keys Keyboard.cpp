// Leetcode : https://leetcode.com/problems/2-keys-keyboard/description/

// [C++]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion + Memoization) - O(n^2) time and O(n^2) space
class Solution
{
    int t[1001][1001];
    int solve(int currentA, int clipboard, int n)
    {
        // Got the answer, no further operations required
        if (currentA == n)
            return 0;
        if (currentA > n)
            return 1000; // Invalid case, return any large number

        if (t[currentA][clipboard] != -1)
            return t[currentA][clipboard];

        // Copy and Paste operation : 1 + 1, currentA's will double and clipboard will be updated with currentA's
        int copyAndPaste = 2 + solve(currentA + currentA, currentA, n);

        // Paste operation : 1 + 1, currentA's will be updated with clipboard's
        int paste = 1 + solve(currentA + clipboard, clipboard, n);

        // Whatever is minimum, store it and return
        return t[currentA][clipboard] = min(copyAndPaste, paste);
    }

public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        memset(t, -1, sizeof(t));
        return 1 + solve(1, 1, n);
    }
};

// Way - II (Bottom - Up) : O(n^2) time and O(n) space
/*
1. If we have initial x A's which are a factor of n, then we can get n A's by copying x A's and pasting n/x - 1 times (- 1 because they are already present one time).
2. So, we can find the factors of n and then find the minimum steps required to get n A's.
3. We can find all factors from 3 to n and then find the minimum steps required to get n A's.
*/
class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 2;

        vector<int> stepsFori(n + 1);
        stepsFori[0] = 0, stepsFori[1] = 0, stepsFori[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            int factor = i / 2; // Closest factor to i
            while (factor >= 1)
            {
                if (i % factor == 0)
                {
                    // Minimum steps required to get i A's = Minimum steps required to get factor A's + 1 (Copy) + (i / factor) - 1 (Number of Paste ops)
                    stepsFori[i] = stepsFori[factor] + 1 + (i / factor) - 1;
                    break;
                }
                factor--; // If not a factor
            }
        }
        return stepsFori[n];
    }
};

// Way - III (Greedy) : O(n) time and O(1) space
/* Using the approach that when remaining A's are divisible by current A's, then we can do the copy and paste operation. */
class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        int currentA = 1, clipboard = 0;
        int remainingA = n, steps = 0;
        while (currentA < n)
        {
            remainingA = n - currentA;
            // if remaining A's are divisible by current A's, then we can do the copy and paste operation
            if (remainingA % currentA == 0)
            {
                clipboard = currentA;   // copy
                currentA *= 2;          // paste
                steps += 2;
            }
            else
            {
                currentA += clipboard;  // paste
                steps++;
            }
        }
        return steps;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
// Way - I (Recursion + Memoization) - O(n^2) time and O(n^2) space
class Solution
{
    int[][] t = new int[1001][1001];

    int solve(int currentA, int clipboard, int n)
    {
        if (currentA == n)
            return 0;
        if (currentA > n)
            return 1000;

        if (t[currentA][clipboard] != -1)
            return t[currentA][clipboard];

        int copyAndPaste = 2 + solve(currentA + currentA, currentA, n);
        int paste = 1 + solve(currentA + clipboard, clipboard, n);

        return t[currentA][clipboard] = Math.min(copyAndPaste, paste);
    }

    public int minSteps(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 0; i < 1001; i++)
            Arrays.fill(t[i], -1);
        return 1 + solve(1, 1, n);
    }
}

// Way - II (Bottom - Up) : O(n^2) time and O(n) space
class Solution
{
    public int minSteps(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 2;

        int[] stepsFori = new int[n + 1];
        stepsFori[0] = 0;
        stepsFori[1] = 0;
        stepsFori[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            int factor = i / 2;
            while (factor >= 1)
            {
                if (i % factor == 0)
                {
                    stepsFori[i] = stepsFori[factor] + 1 + (i / factor) - 1;
                    break;
                }
                factor--;
            }
        }
        return stepsFori[n];
    }
}

// Way - III (Greedy) : O(n) time and O(1) space
class Solution
{
    public int minSteps(int n)
    {
        if (n == 1)
            return 0;
        int currentA = 1, clipboard = 0;
        int remainingA = n, steps = 0;
        while (currentA < n)
        {
            remainingA = n - currentA;
            if (remainingA % currentA == 0)
            {
                clipboard = currentA;
                currentA *= 2;
                steps += 2;
            }
            else
            {
                currentA += clipboard;
                steps++;
            }
        }
        return steps;
    }
}