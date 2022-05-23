class Solution {
public:
 

int f(vector<string> &v,int index,int m,int n,vector<vector<vector<int>>>&dp)
{
    if(index >= v.size()) return 0;
    
    if(dp[index][m][n] != -1) return dp[index][m][n];
    
    int one = count(v[index].begin(),v[index].end(),'1');
    int zero = v[index].size() - one;
    
    if(m >=zero && n>= one){
        return dp[index][m][n] = max(1+f(v,index+1,m-zero,n-one,dp),f(v,index+1,m,n,dp));
       }
    else{
         return dp[index][m][n] =f(v,index+1,m,n,dp);
     }
}
    
    int findMaxForm(vector<string>& strs, int m, int n) {
       vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    return f(strs,0,m,n,dp);
    }
};