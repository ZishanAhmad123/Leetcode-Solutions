class Solution {
public:
int dp[55][55];
    
    int f (int i,int j,int n,int m,vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        int cost = 0;
        if(i == n-1)
           return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mn = 1e9;
        
        for(int k=0;k<m;k++)
        {
            mn = min(mn, grid[i][j] +f(i+1,k,n,m,grid,moveCost) + moveCost[grid[i][j]][k]);
        }
        
        return dp[i][j] = mn;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int cost = 0 ,res = 1e9 , n = grid.size() , m = grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<m;i++)
        {
            cost = f (0,i,n,m,grid,moveCost);
            res = min(res,cost);
        }
        
        return res;
    }
};