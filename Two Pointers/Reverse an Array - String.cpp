// Leetcode : https://leetcode.com/problems/reverse-string/description/ (String)

// GFG : https://www.geeksforgeeks.org/problems/reverse-an-array/1 (Array)

// ************************************************************{Leetcode}************************************************************
// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Built-in Function) : O(n) time and O(1) space
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

// Way - II (Two Pointers) : O(n) time and O(1) space
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Built-in Function) : O(n) time and O(1) space
/* Need to convert char array to string builder to use built-in function. */

// Way - II (Two Pointers) : O(n) time and O(1) space
class Solution
{
    public void reverseString(char[] s)
    {
        int n = s.length;
        int i = 0, j = n - 1;
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
}

// ************************************************************{GFG}************************************************************
// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Built-in Function) : O(n) time and O(1) space
class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        reverse(arr.begin(), arr.end());
    }
};

// Way - II (Two Pointers) : O(n) time and O(1) space
class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Built-in Function) : O(n) time and O(1) space
/* Need to convert array to list to use built-in function. */

// Way - II (Two Pointers) : O(n) time and O(1) space
class Solution
{
    public void reverseArray(int arr[], int n)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
}