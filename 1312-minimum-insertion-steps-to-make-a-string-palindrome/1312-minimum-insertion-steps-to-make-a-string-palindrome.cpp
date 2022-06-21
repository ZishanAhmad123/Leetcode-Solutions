class Solution {
public:
    int f(int ind1,int ind2,string &x, string &y,vector<vector<int>>&dp ){
       if(ind1<0 || ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(x[ind1]==y[ind2]){
        return dp[ind1][ind2]= 1+f(ind1-1, ind2-1, x, y,dp); 
        }
         return dp[ind1][ind2] =max(f(ind1, ind2-1,x, y,dp), f(ind1-1, ind2, x, y,dp)); 
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();int m=text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
      return  f(n-1, m-1, text1, text2, dp);
    }
    
    int minInsertions(string s) {
        string str=s;
        reverse(str.begin(), str.end());
        int lcs_size= longestCommonSubsequence(s, str);
        return s.size()- lcs_size;
    }
};