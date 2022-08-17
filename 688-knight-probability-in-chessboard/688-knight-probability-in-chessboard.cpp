class Solution {
public:
    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {-1,1,-2,2,-2,2,-1,1};
    double dp[26][26][101];
    
    double solve(int row,int col,int n,int k){
        if(row <0 or col <0 or row >= n or col >= n) return 0;
        
        if(k == 0) return 1;   
        
        if(dp[row][col][k] != 0.0)
            return dp[row][col][k];
        
        double ans = 0.0;
        
        for(int i=0;i<8;i++){
            ans += solve(row+dx[i], col+dy[i], n, k-1);
        }
        
        return dp[row][col][k] = ans/8.0;
    }
    
    double knightProbability(int n, int k, int row, int col) {
      
        memset(dp, 0.0, sizeof(dp));
        double fav = solve(row,col,n,k);
        return fav;
    }
};