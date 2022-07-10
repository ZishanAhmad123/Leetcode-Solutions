class Solution {
public:
   int  f(int ind,vector<int>& cost,vector<int>&dp){
        if(ind>=cost.size())
            return 0;
       if(dp[ind]!=-1)return dp[ind];
       
        int left= f(ind+1, cost,dp) +cost[ind];
          
       int right= f(ind+2, cost,dp)+cost[ind];; 

       return  dp[ind]=min(left, right);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(), -1);
      int start_with_0idx=f(0,cost, dp);
      int start_with_1idx=f(1,cost,dp);
    
    return min(start_with_0idx,start_with_1idx);
    }
};