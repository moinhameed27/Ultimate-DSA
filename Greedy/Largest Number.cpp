// Leetcode : https://leetcode.com/problems/largest-number/

// GFG : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Selection Sort [Comparison])
class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<string> v;
        // Converting all numbers to strings
        for(int num : nums)
            v.push_back(to_string(num));
        
        for(int i = 0; i < n - 1; i++)
        {
            int maxIdx = i;
            for(int j = i + 1; j < n; j++)
            {
                // s1 = "3", s2 = "30" --> "330" > "303"
                if(v[j] + v[maxIdx] > v[maxIdx] + v[j])
                    maxIdx = j;
            }
            swap(v[i], v[minIdx]);
        }

        // Corner Case
        if(v[0] == "0")
            return "0";

        string ans;
        for(string num : v)
            ans += num;
        return ans;
    }
};

// Way - II (Built-In Sorting [Comparator])
class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        auto myComparator = [](int a, int b)
        {
            string s1 = to_string(a), s2 = to_string(b);
            return s1 + s2 > s2 + s1;
        };

        sort(nums.begin(), nums.end(), myComparator);

        if(nums[0] == 0)
            return "0";
        
        string ans;
        for(int num : nums)
            ans += to_string(num);

        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Selection Sort [Comparison])
class Solution 
{
    public String largestNumber(int[] nums) 
    {
        int n = nums.length;
        List<String> v = new ArrayList<>();
        
        // Converting all numbers to strings
        for (int num : nums)
            v.add(String.valueOf(num));
        
        // Sort using a custom comparator
        for (int i = 0; i < n - 1; i++) 
        {
            int maxIdx = i;
            for (int j = i + 1; j < n; j++) 
            {
                // s1 = "3", s2 = "30" --> "330" > "303"
                if ((v.get(j) + v.get(maxIdx)).compareTo(v.get(maxIdx) + v.get(j)) > 0)
                    maxIdx = j;
            }
            // Swap v[i] and v[maxIdx]
            Collections.swap(v, i, maxIdx);
        }

        // Corner case for "000...0"
        if (v.get(0).equals("0"))
            return "0";

        StringBuilder ans = new StringBuilder();
        for (String num : v)
            ans.append(num);

        return ans.toString();
    }
}

// Way - II (Built-In Sorting [Comparator])
class Solution 
{
    public String largestNumber(int[] nums) 
    {
        List<String> numList = new ArrayList<>();
        for (int num : nums) 
            numList.add(String.valueOf(num));

        Collections.sort(numList, (a, b) -> (b + a).compareTo(a + b));

        if (numList.get(0).equals("0")) 
            return "0";

        StringBuilder result = new StringBuilder();
        for (String num : numList) 
            result.append(num);

        return result.toString();
    }
}



/*
Important points about strings comparison:
1. s1 = "234", s2 = "235" --> s1 > s2
2. s1 = "223", s2 = "24" --> s2 > s1
*/