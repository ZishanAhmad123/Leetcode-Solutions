class Solution {
public:
  int dp[601][101][101];

int f(vector<string> &v,int index,int m,int n)
{
    if(index >= v.size()) return 0;
    
    if(dp[index][m][n] != -1) return dp[index][m][n];
    
    int one = count(v[index].begin(),v[index].end(),'1');
    int zero = v[index].size() - one;
    
    if(m >=zero && n>= one){
        return dp[index][m][n] = max(1+f(v,index+1,m-zero,n-one),f(v,index+1,m,n));
       }
    else{
         return dp[index][m][n] =f(v,index+1,m,n);
     }
}
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
   // vector<vector<vector<int> > > dp(601,vector<vector<int> >(101,vector <int>(101,-1)));  //dp
    return f(strs,0,m,n);
    }
};