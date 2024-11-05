// Leetcode : https://leetcode.com/problems/rotate-image/description/

// GFG : https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I : O(n^2) time and O(n^2) space
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dupMatrix = matrix;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int index = cols - j - 1;
                matrix[i][j] = dupMatrix[index][i];
            }
        }
    }
};

// Way - II (Transpose and reverse) : O(n^2) time and O(1) space
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I : O(n^2) time and O(n^2) space
class Solution
{
    public void rotate(int[][] matrix)
    {
        int rows = matrix.length, cols = matrix[0].length;
        int[][] dupMatrix = new int[rows][cols];

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                dupMatrix[i][j] = matrix[i][j];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int index = cols - j - 1;
                matrix[i][j] = dupMatrix[index][i];
            }
        }
    }
}

// Way - II (Transpose and reverse) : O(n^2) time and O(1) space
class Solution
{
    public void rotate(int[][] matrix)
    {
        int n = matrix.length;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix, i, j);
        }

        for (int i = 0; i < n; i++)
            reverse(matrix[i]);
    }

    private void swap(int[][] matrix, int i, int j)
    {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }

    private void reverse(int[] arr)
    {
        int n = arr.length;
        for (int i = 0; i < n / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }
}