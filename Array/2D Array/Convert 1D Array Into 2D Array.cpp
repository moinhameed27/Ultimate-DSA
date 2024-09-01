// Leetcode : https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int size = original.size();
        // Not Possible to Construct a 2D Array
        if (size != m * n)
            return {};
        int a = 0, b = 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < size; i++)
        {
            matrix[a][b] = original[i];
            b++;
            // If b reaches no of cols, then move to next row starting from first column
            if (b == n)
                a++, b = 0;
        }
        return matrix;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int size = original.length;
        // Not Possible to Construct a 2D Array
        if (size != m * n)
            return new int[][] {};
        int a = 0, b = 0;
        int[][] matrix = new int[m][n];
        for (int i = 0; i < size; i++) {
            matrix[a][b] = original[i];
            b++;
            // If b reaches no of cols, then move to next row starting from first column
            if (b == n)
            {
                a++; 
                b = 0;
            }
        }
        return matrix;
    }
}