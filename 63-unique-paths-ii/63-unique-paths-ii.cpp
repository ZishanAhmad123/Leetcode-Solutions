class Solution {
public:
    
       int f(int i, int j,  vector<vector<int>>&dp,vector<vector<int>>&grid){
           
        if( i>=0 && j>=0 && grid[i][j]==1) return 0;   // for checking Obstacle 1  
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int up=f(i-1, j,dp, grid);
        int left=f(i, j-1,dp,grid);
        
        return dp[i][j]=up+left;
    }
   
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n, -1));
        return f(m-1, n-1,dp, grid);
    }
}; 
