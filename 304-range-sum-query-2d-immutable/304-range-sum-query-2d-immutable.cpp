class NumMatrix
{
    int row;
    int col;
    vector<vector<int>> grid;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        row = matrix.size();
        col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                if (j - 1 >= 0)
                {
                    matrix[i][j] += matrix[i][j - 1];
                }

                if (i - 1 >= 0)
                {
                    matrix[i][j] += matrix[i - 1][j];
                }

                if (i - 1 >= 0 and j - 1 >= 0)
                {
                    matrix[i][j] -= matrix[i - 1][j - 1];
                }
            }
        }
        grid = matrix;  
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum1 = grid[row2][col2];
        int sum2 = 0;
        if (col1 - 1 >= 0)
        {
            sum2 = grid[row2][col1 - 1];
        }
        int sum3 = 0;
        if (row1 - 1 >= 0)
        {
            sum3 = grid[row1 - 1][col2];
        }
        int sum4 = 0;
        if (row1 - 1 >= 0 and col1 - 1 >= 0)
        {
            sum4 = grid[row1 - 1][col1 - 1];
        }

        
        
        return sum1 - sum2 - sum3 + sum4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */