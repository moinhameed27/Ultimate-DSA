// GFG : https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1 

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();
        int sum1 = 0, sum2 = 0;
        int ans = 0;
        int i = 0, j = 0;
        while (i < n1 || j < n2)
        {
            // If both elements are same, then add the maximum of sum1 and sum2 to the answer
            if (i < n1 && j < n2 && arr1[i] == arr2[j])
            {
                ans += max(sum1 + arr1[i], sum2 + arr2[j]);
                // Reset the sums
                sum1 = 0, sum2 = 0;
                // Increment both pointers as only one common element is allowed
                i++, j++;
            }
            else if (i < n1 && (j >= n2 || arr1[i] < arr2[j]))
                sum1 += arr1[i++];
            else if (j < n2 && (i >= n1 || arr2[j] < arr1[i]))
                sum2 += arr2[j++];
        }
        ans += max(sum1, sum2);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    public int maxPathSum(List<Integer> arr1, List<Integer> arr2)
    {
        int n1 = arr1.size(), n2 = arr2.size();
        int sum1 = 0, sum2 = 0;
        int ans = 0;
        int i = 0, j = 0;
        while (i < n1 || j < n2)
        {
            // If both elements are same, then add the maximum of sum1 and sum2 to the answer
            if (i < n1 && j < n2 && arr1.get(i) == arr2.get(j))
            {
                ans += Math.max(sum1 + arr1.get(i), sum2 + arr2.get(j));
                // Reset the sums
                sum1 = 0;
                sum2 = 0;
                // Increment both pointers as only one common element is allowed
                i++;
                j++;
            }
            else if (i < n1 && (j >= n2 || arr1.get(i) < arr2.get(j)))
                sum1 += arr1.get(i++);
            else if (j < n2 && (i >= n1 || arr2.get(j) < arr1.get(i)))
                sum2 += arr2.get(j++);
        }
        ans += Math.max(sum1, sum2);
        return ans;
    }
}