class Solution {
public:
   int f(int n,vector<int> &nums ,vector<int> &dp){

if(n==0)
return nums[n];
if(n<0)
return 0;
    
if(dp[n]!=-1)
return dp[n];

     int pick =nums[n]+f(n-2,nums,dp);
     int notpick=0+f(n-1,nums,dp);

    return dp[n]=max(pick,notpick);  
}
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>values(n, 0);
        vector<int>dp(10002,-1);
        for(auto num: nums)values[num]+=num;
        return f(n-1, values, dp);
        
    
    }
};