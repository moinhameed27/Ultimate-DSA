// Leetcode : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Hashing)
/* Store each current state of vowels in the map. When state is found again, it means subarray is of even vowels. */
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.size(), ans = 0;
        unordered_map<string, int> mp;
        vector<int> vowelParity(5, 0); // a, e, i, o, u
        string currentState = "00000";
        mp[currentState] = -1; // Initial state

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == 'a')
                vowelParity[0] = (vowelParity[0] + 1) % 2;
            else if (ch == 'e')
                vowelParity[1] = (vowelParity[1] + 1) % 2;
            else if (ch == 'i')
                vowelParity[2] = (vowelParity[2] + 1) % 2;
            else if (ch == 'o')
                vowelParity[3] = (vowelParity[3] + 1) % 2;
            else if (ch == 'u')
                vowelParity[4] = (vowelParity[4] + 1) % 2;

            currentState = "";
            for (int i : vowelParity)
                currentState += to_string(i);

            if (mp.find(currentState) != mp.end())
                ans = max(ans, i - mp[currentState]);
            else
                mp[currentState] = i;
        }
        return ans;
    }
};

// Way - II (Changes in Way - I [XOR])
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.size(), ans = 0;
        unordered_map<string, int> mp;
        vector<int> vowelParity(5, 0); // a, e, i, o, u
        string currentState = "00000";
        mp[currentState] = -1; // Initial state

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == 'a')
                vowelParity[0] ^= 1;
            else if (ch == 'e')
                vowelParity[1] ^= 1;
            else if (ch == 'i')
                vowelParity[2] ^= 1;
            else if (ch == 'o')
                vowelParity[3] ^= 1;
            else if (ch == 'u')
                vowelParity[4] ^= 1;

            currentState = "";
            for (int i : vowelParity)
                currentState += to_string(i);

            if (mp.find(currentState) != mp.end())
                ans = max(ans, i - mp[currentState]);
            else
                mp[currentState] = i;
        }
        return ans;
    }
};

// Way - III (Bitmask and XOR)
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.size(), ans = 0, mask = 0;    // mask to store the state of vowels u, i, o, e, a (R to L bits)
        unordered_map<int, int> mp;
        mp[mask] = -1;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            // XOR with 1 to toggle the bit
            if (ch == 'a')
                mask ^= (1 << 0);
            else if (ch == 'e')
                mask ^= (1 << 1);
            else if (ch == 'i')
                mask ^= (1 << 2);
            else if (ch == 'o')
                mask ^= (1 << 3);
            else if (ch == 'u')
                mask ^= (1 << 4);

            if (mp.find(mask) != mp.end())
                ans = max(ans, i - mp[mask]);
            else
                mp[mask] = i;
        }
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Hashing)
class Solution 
{
    public int findTheLongestSubstring(String s) 
    {
        int n = s.length(), ans = 0;
        Map<String, Integer> mp = new HashMap<>();
        int[] vowelParity = new int[5]; // a, e, i, o, u
        String currentState = "00000";
        mp.put(currentState, -1); // Initial state

        for (int i = 0; i < n; i++) 
        {
            char ch = s.charAt(i);
            if (ch == 'a')
                vowelParity[0] = (vowelParity[0] + 1) % 2;
            else if (ch == 'e')
                vowelParity[1] = (vowelParity[1] + 1) % 2;
            else if (ch == 'i')
                vowelParity[2] = (vowelParity[2] + 1) % 2;
            else if (ch == 'o')
                vowelParity[3] = (vowelParity[3] + 1) % 2;
            else if (ch == 'u')
                vowelParity[4] = (vowelParity[4] + 1) % 2;

            currentState = "";
            for (int v : vowelParity)
                currentState += v;

            if (mp.containsKey(currentState))
                ans = Math.max(ans, i - mp.get(currentState));
            else
                mp.put(currentState, i);
        }
        return ans;
    }
}

// Way - II (Changes in Way - I [XOR])
class Solution 
{
    public int findTheLongestSubstring(String s) 
    {
        int n = s.length(), ans = 0;
        Map<String, Integer> mp = new HashMap<>();
        int[] vowelParity = new int[5]; // a, e, i, o, u
        String currentState = "00000";
        mp.put(currentState, -1); // Initial state

        for (int i = 0; i < n; i++) 
        {
            char ch = s.charAt(i);
            if (ch == 'a')
                vowelParity[0] ^= 1;
            else if (ch == 'e')
                vowelParity[1] ^= 1;
            else if (ch == 'i')
                vowelParity[2] ^= 1;
            else if (ch == 'o')
                vowelParity[3] ^= 1;
            else if (ch == 'u')
                vowelParity[4] ^= 1;

            currentState = "";
            for (int v : vowelParity)
                currentState += v;

            if (mp.containsKey(currentState))
                ans = Math.max(ans, i - mp.get(currentState));
            else
                mp.put(currentState, i);
        }
        return ans;
    }
}

// Way - III (Bitmask and XOR)
class Solution 
{
    public int findTheLongestSubstring(String s) 
    {
        int n = s.length(), ans = 0, mask = 0;    // mask to store the state of vowels u, i, o, e, a (R to L bits)
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(mask, -1);

        for (int i = 0; i < n; i++) 
        {
            char ch = s.charAt(i);
            // XOR with 1 to toggle the bit
            if (ch == 'a')
                mask ^= (1 << 0);
            else if (ch == 'e')
                mask ^= (1 << 1);
            else if (ch == 'i')
                mask ^= (1 << 2);
            else if (ch == 'o')
                mask ^= (1 << 3);
            else if (ch == 'u')
                mask ^= (1 << 4);

            if (mp.containsKey(mask))
                ans = Math.max(ans, i - mp.get(mask));
            else
                mp.put(mask, i);
        }
        return ans;
    }
}