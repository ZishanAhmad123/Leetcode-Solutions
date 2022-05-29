class Solution {
public:
     
    int f(long long n,  unordered_map<int,int>&dp){
    
        if(n == 1) 
            return 0;
        if(dp[n]) 
            return dp[n];
        if(n%2)
            return dp[n] = 1 + min(f(n-1, dp), f(n+1,dp));
        else
            return dp[n] = 1 +f(n/2,dp);
    }
    int integerReplacement(int n) {
        unordered_map<int,int> dp;
        dp.clear();
     return   f(n,dp);
    }
};