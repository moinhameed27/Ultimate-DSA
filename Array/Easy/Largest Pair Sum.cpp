// GFG : https://www.geeksforgeeks.org/problems/pair-sum--120604/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting]) : O(nlogn) time and O(1) space
class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[n - 1] + arr[n - 2];
    }
};

// Way - II (Optimal [Max and Second Max]) : O(n) time and O(1) space
/* 
1. If current number is greater than maxi, update secMaxi to maxi and maxi to current number.
2. Else if current number is greater than secMaxi, update secMaxi to current number.
*/
class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN, secMaxi = INT_MIN;
        for (int num : arr)
        {
            if (num > maxi)
            {
                secMaxi = maxi;
                maxi = num;
            }
            else if (num > secMaxi)
                secMaxi = num;
        }
        return maxi + secMaxi;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting]) : O(nlogn) time and O(1) space
class Solution 
{
    public static int pairsum(int[] arr) 
    {
        int n = arr.length;
        Arrays.sort(arr);
        return arr[n - 1] + arr[n - 2];
    }
}

// Way - II (Optimal [Max and Second Max]) : O(n) time and O(1) space
/* 
1. If current number is greater than maxi, update secMaxi to maxi and maxi to current number.
2. Else if current number is greater than secMaxi, update secMaxi to current number.
*/
class Solution 
{
    public static int pairsum(int[] arr) 
    {
        int n = arr.length;
        int maxi = Integer.MIN_VALUE, secMaxi = Integer.MIN_VALUE;
        for(int num : arr)
        {
            if(num > maxi)    
            {
                secMaxi = maxi;
                maxi = num;
            }
            else if (num > secMaxi)
                secMaxi = num;
        }
        return maxi + secMaxi;
    }
}