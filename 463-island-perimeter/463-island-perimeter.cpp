class Solution {
public:
    void solve(int i,int j,int n,int m,vector<vector<int>>& grid,int &cnt){
        if(i<0 || j<0 || i==n || j==m || grid[i][j]==0){
            cnt++;
            return;
        }
       
        if(grid[i][j]==-1) return;
        grid[i][j]=-1;
        solve(i+1,j,n,m,grid,cnt);
        solve(i,j+1,n,m,grid,cnt);
        solve(i-1,j,n,m,grid,cnt);
        solve(i,j-1,n,m,grid,cnt);
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
       for(int i=0; i<grid.size(); i++){
           for(int j=0; j<grid[0].size(); j++){
               if(grid[i][j]==1){
                   solve(i,j,n,m,grid,count);
               }
           }
       }
        
        return count;
    }
};