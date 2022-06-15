class Solution {
public:
    int lnds(vector<int>& nums, int i,int prev, vector<vector<int>>&dp){
        if(nums.size()==i)return 0;
        
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];                //prev+1 in dp because of grid have no -1 index to handle  this we use coordinate shift by +1
        
        int len=0+lnds(nums, i+1, prev,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            len=max(len, 1+lnds(nums, i+1, i,dp));
        }
        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return lnds(nums, 0, -1, dp);
    }
};