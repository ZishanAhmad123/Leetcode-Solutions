class Solution {
public:
     int pickedColor;
    int n, m;
    vector<vector<int>> result;
     bool Boundary(vector<vector<int>>& grid, int x, int y) {
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1 ||
                grid[x][y + 1] != pickedColor || grid[x][y - 1] != pickedColor
                || grid[x + 1][y] != pickedColor || grid[x - 1][y] != pickedColor)
            return true;
        return false;
    }
    
     void floodFill(vector<vector<int>> &grid, int x, int y, int color, vector<vector<int>> &visited)
    {
        // fill current island with water
        visited[x][y] = 1;

        if (Boundary(grid, x, y)) result[x][y] = color;

        // traverse all the  directions
         int dx[4] = {0, 0, 1, -1};
         int dy[4] = {1, -1, 0, 0};
        for (int dir = 0; dir < 4; dir++)
        {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            // checking boundary conditions
            if (newX >= 0 && newX < n && newY >= 0 && newY < m
                    && !visited[newX][newY] && grid[newX][newY] == pickedColor)
            {
                floodFill(grid, newX, newY, color, visited);
            }
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
         n = grid.size();
        m = grid[0].size();

        // store the picked color
        pickedColor = grid[row][col];
        // visited array
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // resultant array
        result = grid;
        // calling flood fill to color boundary
        floodFill(grid, row, col, color, visited);
        return result;
    }
};