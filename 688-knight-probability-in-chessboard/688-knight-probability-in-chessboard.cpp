class Solution {
public:
    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {-1,1,-2,2,-2,2,-1,1};
    double dp[26][26][101];
    
    double solve(int row,int col,int n,int k){
        if(row <0 or col <0 or row >= n or col >= n) return 0;
        
        if(k == 0) return 1.0;   
        
        if(dp[row][col][k] != 0.0)
            return dp[row][col][k];
        
        double ans = 0.0;
        
        for(int i=0;i<8;i++){
           int ni = row + dx[i] , nj = col + dy[i];      // Make new coordinates after one move
           if(ni >= 0 && nj >= 0 && ni < n && nj < n) 
            ans+=solve(ni,nj,n,k-1) * (0.125); 
        }
        
        return dp[row][col][k] = ans;
    }
    
    double knightProbability(int n, int k, int row, int col) {
      
        memset(dp, 0.0, sizeof(dp));
        double fav = solve(row,col,n,k);
        return fav;
    }
};