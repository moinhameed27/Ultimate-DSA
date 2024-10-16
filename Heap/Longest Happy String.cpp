// Leetcode : https://leetcode.com/problems/longest-happy-string/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Simple Conditions) : O(a + b + c) time and O(1) space
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int currA = 0, currB = 0, currC = 0;
        int i = 0, maxLength = a + b + c;
        string ans;
        while (i < maxLength)
        {
            // If a is the largest and not used twice in a row, or if a is the only one left and any other is used twice
            if ((currA != 2 && a >= b && a >= c) ||
                (a > 0 && (currB == 2 || currC == 2)))
            {
                ans += 'a';
                a--;
                currA++;
                currB = 0;
                currC = 0;
            }
            // If b is the largest and not used twice in a row, or if b is the only one left and any other is used twice
            else if ((currB != 2 && b >= a && b >= c) ||
                     (b > 0 && (currA == 2 || currC == 2)))
            {
                ans += 'b';
                b--;
                currB++;
                currA = 0;
                currC = 0;
            }
            // If c is the largest and not used twice in a row, or if c is the only one left and any other is used twice
            else if ((currC != 2 && c >= a && c >= b) ||
                     (c > 0 && (currA == 2 || currB == 2)))
            {
                ans += 'c';
                c--;
                currC++;
                currA = 0;
                currB = 0;
            }
            i++;
        }
        return ans;
    }
};

// Way - II (Priority Queue [Max Heap]) : O(a + b + c) time and O(3) space
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        priority_queue<pair<int, char>> pq; // Max Heap of pair<freq, char>

        // Pushing the characters with their frequencies in the max heap
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        while (!pq.empty())
        {
            auto [currentCount, currentChar] = pq.top();
            pq.pop();
            int n = ans.size();
            // If the last two characters are same as the current character, then we need to choose the next character
            if (n >= 2 && ans[n - 1] == currentChar && ans[n - 2] == currentChar)
            {
                if (pq.empty())
                    break;
                auto [nextCount, nextChar] = pq.top();
                pq.pop();
                ans += nextChar;
                nextCount--;
                // If the next character is still available, then push it back to the heap
                if (nextCount > 0)
                    pq.push({nextCount, nextChar});
            }
            // If the current character is still available, then add it to the answer
            else
            {
                ans += currentChar;
                currentCount--;
            }

            // If the current character is still available, then push it back to the heap
            if (currentCount > 0)
                pq.push({currentCount, currentChar});
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Simple Conditions) : O(a + b + c) time and O(1) space
class Solution
{
    public String longestDiverseString(int a, int b, int c)
    {
        int currA = 0, currB = 0, currC = 0;
        int i = 0, maxLength = a + b + c;
        StringBuilder ans = new StringBuilder();
        while (i < maxLength)
        {
            // If a is the largest and not used twice in a row, or if a is the only one left and any other is used twice
            if ((currA != 2 && a >= b && a >= c) ||
                (a > 0 && (currB == 2 || currC == 2)))
            {
                ans.append('a');
                a--;
                currA++;
                currB = 0;
                currC = 0;
            }
            // If b is the largest and not used twice in a row, or if b is the only one left and any other is used twice
            else if ((currB != 2 && b >= a && b >= c) ||
                     (b > 0 && (currA == 2 || currC == 2)))
            {
                ans.append('b');
                b--;
                currB++;
                currA = 0;
                currC = 0;
            }
            // If c is the largest and not used twice in a row, or if c is the only one left and any other is used twice
            else if ((currC != 2 && c >= a && c >= b) ||
                     (c > 0 && (currA == 2 || currB == 2)))
            {
                ans.append('c');
                c--;
                currC++;
                currA = 0;
                currB = 0;
            }
            i++;
        }
        return ans.toString();
    }
}

// Way - II (Priority Queue [Max Heap]) : O(a + b + c) time and O(3) space
class Solution
{
    public String longestDiverseString(int a, int b, int c)
    {
        StringBuilder ans = new StringBuilder();
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]); // Max Heap of pair<freq, char>

        // Pushing the characters with their frequencies in the max heap
        if (a > 0)
            pq.add(new int[]{a, 'a'});
        if (b > 0)
            pq.add(new int[]{b, 'b'});
        if (c > 0)
            pq.add(new int[]{c, 'c'});

        while (!pq.isEmpty())
        {
            int[] current = pq.poll();
            int currentCount = current[0];
            char currentChar = (char) current[1];
            int n = ans.length();
            // If the last two characters are same as the current character, then we need to choose the next character
            if (n >= 2 && ans.charAt(n - 1) == currentChar && ans.charAt(n - 2) == currentChar)
            {
                if (pq.isEmpty())
                    break;
                int[] next = pq.poll();
                char nextChar = (char) next[1];
                ans.append(nextChar);
                next[0]--;
                // If the next character is still available, then push it back to the heap
                if (next[0] > 0)
                    pq.add(next);
            }
            // If the current character is still available, then add it to the answer
            else
            {
                ans.append(currentChar);
                currentCount--;
            }

            // If the current character is still available, then push it back to the heap
            if (currentCount > 0)
                pq.add(new int[]{currentCount, currentChar});
        }
        return ans.toString();
    }
}