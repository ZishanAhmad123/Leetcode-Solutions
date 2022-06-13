class Solution {
public:



int minimumTotal(vector<vector<int>>& triangle) {
    
    
    int n=triangle.size();
    int m=triangle[n-1].size();   // we need last row having no.of number of column
    
    vector<vector<int>>dp(n,vector<int>(m, 0));
    
    
    for(int j=0;j<m;j++)
    {
        dp[n-1][j]=triangle[n-1][j];
    }
    
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j]=min(down,dg);
        }
    }
    return dp[0][0];
    
}


};