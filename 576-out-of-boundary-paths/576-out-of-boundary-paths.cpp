class Solution {
public:
    
    int dp[55][55][55];
    long long  mod = 1000000007;
    long dfs(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow >= m or startRow < 0 or startColumn >= n or startColumn < 0){
            return 1;}
        
        if(maxMove <= 0){
            return 0;
        }
        if(dp[startRow][startColumn][maxMove] != -1){
            return dp[startRow][startColumn][maxMove];
        }
    
        int up= dfs(m, n, maxMove - 1, startRow - 1, startColumn);
        int down= dfs(m, n, maxMove - 1, startRow, startColumn + 1);
        int right= dfs(m, n, maxMove - 1, startRow + 1, startColumn);
        int left= dfs(m, n, maxMove - 1, startRow, startColumn - 1);
        
         long total= (up%mod+down%mod+ right%mod+ left%mod)%mod;
        
        return dp[startRow][startColumn][maxMove] =total;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
         return dfs(m, n, maxMove, startRow, startColumn);
    }
};