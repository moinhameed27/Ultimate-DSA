// LeetCode : https://leetcode.com/problems/merge-sorted-array/description/

// Way - I (Brute Force [Built-in sort])
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
            nums1[i + m] = nums2[i];
        sort(nums1.begin(), nums1.end());
    }
};

// Way - II (Two Pointer)
/* Start from the back, greater element is placed and pointer is decremented. At the end, check if there are still elements left in nums2 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Traverse backwards : i(End of nums1 elements), j(End of nums2), k(End of nums1 - Place to insert)
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        // If there are still elements left in nums2
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

/* Here, there's no point to check whether loop failed due to nums2 and check for nums1 remaining elements, because nums1 elements
are already sorted in increasing order. If nums2 elements are placed in the correct order, nums1 are already placed in correct order */

// Way - III (Two Pointer [2])
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        // By Comparing, put the elements in the correct order and check for bounds
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};