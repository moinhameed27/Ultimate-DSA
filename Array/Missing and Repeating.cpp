// GFG : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space [TLE]
class Solution 
{
  public:
    vector<int> findTwoElement(vector<int>& arr) 
    {
        int a, b;
        int n = arr.size();
        for(int i = 1; i <= n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(arr[j] == i)
                    count++;
            }
            if(count == 2)
                a = i;
            if(count == 0)
                b = i;
        }
        return {a, b};
    }
};

// Way - II (Storing Frequencies) : O(n) time and o(n) space
class Solution 
{
  public:
    vector<int> findTwoElement(vector<int>& arr) 
    {
        int a, b;
        int n = arr.size();
        vector<int> freq(n + 1, 0);
        for(int i : arr)
            freq[i]++;
        
        for(int i = 1; i <= n; i++)
        {
            if(freq[i] == 2)
                a = i;
            if(freq[i] == 0)
                b = i;
        }
        return {a, b};
    }
}; 



// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force) : O(n ^ 2) time and O(1) space [TLE]
class Solve 
{
    int[] findTwoElement(int arr[]) 
    {
        int[] ans = new int[2];
        int n = arr.length;
        for(int i = 1; i <= n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(arr[j] == i)
                    count++;
            }
            if(count == 2)
                ans[0] = i;
            if(count == 0)
                ans[1] = i;
        }
        return ans;
    }
}

// Way - II (Storing Frequencies) : O(n) time and o(n) space
class Solve 
{
    int[] findTwoElement(int arr[]) 
    {
        int n = arr.length;
        int[] ans = new int[2];
        int[] freq = new int[n + 1];
        for(int i : arr)
            freq[i]++;
        
        for(int i = 1; i <= n; i++)
        {
            if(freq[i] == 2)
                ans[0] = i;
            if(freq[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
}
