class Solution {
public:
    int mod =1000000007;
    int countPalindromicSubsequences(string S) {
          int n=S.length();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n-1;i++) dp[i][i]=1,dp[i][i+1]=2; 
        dp[n-1][n-1]=1; 
        
        for(int sz=3;sz<=n;sz++){
            for(int i=0;i<n-sz+1;i++){
                int j=i+sz-1;
                if(S[i]==S[j]){
                    int low = i + 1; 
                    int high = j - 1;
                    while(low <= high && S[low] != S[j]) low++;
                    while(low <= high && S[high] != S[j]) high--;
                   
                    if(low==high) dp[i][j]=dp[i+1][j-1]*2 +1; 
                    else if(low>high) dp[i][j]=dp[i+1][j-1]*2 +2; 
                     else dp[i][j]=dp[i+1][j-1]*2 - dp[low+1][high-1]; 
                }
                else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]; 
                
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + mod  : dp[i][j] % mod; 
            }                                        
            
        }
        return dp[0][n-1];
    }
};