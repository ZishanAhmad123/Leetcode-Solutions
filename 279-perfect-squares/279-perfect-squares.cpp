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
    
    vector<int> getNumbers(int n){
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(i*i <= n) res.push_back(i*i);
        else{
            break;
        }
    }
    return res;
}
    
    int numSquares(int amount) {
         vector<int> coins = getNumbers(amount);
    int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans=   f(n-1, amount, coins,dp);
         if(ans>=1e9) return -1;
         return ans;  
    }
};