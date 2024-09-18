// Leetcode : https://leetcode.com/problems/largest-number/

// GFG : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
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