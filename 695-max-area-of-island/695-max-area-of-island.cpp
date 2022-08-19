class Solution {
public:
    
    int bfs(vector<vector<int>>& grid, int i , int j, vector<vector<bool>> &visited,int count) {
       // Code here
       
       int n = grid.size();
       int m = grid[0].size();
       
      int dx[4]={1,-1,0,0};
      int dy[4]={0,0,1,-1};
       
       queue<pair<int,int>> q;
       q.push({i,j});
       visited[i][j] =1;
       count++;
       
       while(!q.empty()){
           auto f = q.front();
           int x = f.first;
           int y = f.second;
           q.pop();
           for(int k=0;k<4;k++){
               int nexti = x+ dx[k];
               int nextj = y+ dy[k];
               
               if(nexti>=0 && nexti<n && nextj>=0 && nextj<m && !visited[nexti][nextj] && grid[nexti][nextj]==1){
                   count++;
                   q.push({nexti,nextj});
                   visited[nexti][nextj] = true;
                   
               }
           }
       }
       return count;
   }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int maxcount = 0;
            int n = grid.size();
            int m = grid[0].size();
       
          vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
           
                  if(grid[i][j]==1  && !visited[i][j]){
                   int count = bfs(grid,i,j,visited,0); //count gets updated
                   maxcount = max(maxcount ,count );
                  }
           }
       }
       return maxcount ;
}

     
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
    
};