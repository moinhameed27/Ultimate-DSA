// Leetcode : https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (1D Array Loop)
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

// Way - II (2D Array Loop)
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int size = original.size();
        if (size != m * n)
            return {};
        int idx = 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = original[idx++];
        }
        return matrix;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (1D Array Loop)
class Solution
{
    public int[][] construct2DArray(int[] original, int m, int n)
    {
        int size = original.length;
        // Not Possible to Construct a 2D Array
        if (size != m * n)
            return new int[][]{};
        int a = 0, b = 0;
        int[][] matrix = new int[m][n];
        for (int i = 0; i < size; i++)
        {
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

// Way - II (2D Array Loop)
class Solution
{
    public int[][] construct2DArray(int[] original, int m, int n)
    {
        int size = original.length;
        if (size != m * n)
            return new int[][]{};
        int idx = 0;
        int[][] matrix = new int[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = original[idx++];
        }
        return matrix;
    }
}