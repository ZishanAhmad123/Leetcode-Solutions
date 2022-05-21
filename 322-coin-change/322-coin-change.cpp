class Solution {
public:
    int f(int ind, int T ,vector<int>& coins, vector<vector<int>>&dp ){
        if(ind==0){
            if(T%coins[ind]==0)return T/coins[ind];
            return 1e9;
        }
        if(dp[ind][T]!=-1)return dp[ind][T];
        int nottake=0 + f(ind-1, T, coins,dp);
        int take=INT_MAX;
        if(coins[ind]<=T){
            take=1+ f(ind, T-coins[ind], coins,dp);     //infinite supply
        }
        return  dp[ind][T]= min(take, nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
     int ans=   f(n-1, amount, coins,dp);
         if(ans>=1e9) return -1;
        return ans;
    }

 };
