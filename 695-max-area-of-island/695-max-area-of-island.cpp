class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int max_area=0;
    int row = grid.size();
    int col = grid[0].size();
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(grid[i][j]==1)
                max_area = max(max_area , dfs(grid, i, j));

    return max_area;
}
int dfs(vector<vector<int>>& grid, int i, int j)
{
     if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
        grid[i][j] = 0;
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    return 0;
        
     
//         int Max=0;
//          int row = grid.size();
//     int col = grid[0].size();
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//                int  cnt=1;
//             if( grid[i][j]==1){
//                 dfs(grid, i, j, cnt);
//                Max = max(Max, cnt);  }  
//         }
//     }
//        return Max;
//     }
//     int dfs(vector<vector<int>>& grid, int i, int j, int& cnt){
//         if( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
//       return 0;
//         }
//         grid[i][j]=0;
//         if(dfs(grid, i+1,j, cnt))cnt++;
//          if(dfs(grid, i-1,j, cnt))cnt++;
//          if(dfs(grid, i,j-1, cnt))cnt++;
//          if(dfs(grid, i,j+1, cnt))cnt++;
//         return 1;
    }
    
};