// Leetcode : https://leetcode.com/problems/sort-colors/description/

// GFG : https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting])
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }
};

// Way - II (Overwriting)
/* Count number of 0s, 1s and 2s and then place them in the sorted order */
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zeros = count(nums.begin(), nums.end(), 0);
        int ones = count(nums.begin(), nums.end(), 1);
        int twos = count(nums.begin(), nums.end(), 2);

        int i = 0;
        while (zeros--)
            nums[i++] = 0;
        while (ones--)
            nums[i++] = 1;
        while (twos--)
            nums[i++] = 2;
    }
};

// Way - III (Two Pointers [Dutsch National Flag Algo])
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int a = 0, b = 0, c = n - 1;

        while (b <= c)
        {
            if (nums[b] == 0)
            {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            else if (nums[b] == 1)
                b++;
            else
            {
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Sorting])
class Solution
{
    public void sortColors(int[] nums)
    {
        Arrays.sort(nums);
    }
}

// Way - II (Overwriting)
class Solution
{
    public void sortColors(int[] nums)
    {
        int zeros = 0, ones = 0, twos = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] == 0)
                zeros++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }
        int i = 0;
        while (zeros-- > 0)
            nums[i++] = 0;
        while (ones-- > 0)
            nums[i++] = 1;
        while (twos-- > 0)
            nums[i++] = 2;
    }
}

// Way - III (Two Pointers [Dutsch National Flag Algo])
class Solution
{
    public void sortColors(int[] nums)
    {
        int a = 0, b = 0, c = nums.length - 1;
        while (b <= c)
        {
            if (nums[b] == 0)
            {
                int temp = nums[a];
                nums[a] = nums[b];
                nums[b] = temp;
                a++;
                b++;
            }
            else if (nums[b] == 1)
                b++;
            else
            {
                int temp = nums[b];
                nums[b] = nums[c];
                nums[c] = temp;
                c--;
            }
        }
    }
}