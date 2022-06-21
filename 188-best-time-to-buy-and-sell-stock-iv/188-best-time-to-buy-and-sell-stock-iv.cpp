class Solution {
public:
    int f(int index,int buy,int cap,vector<int>& prices, int n,vector<vector<vector<int>>>&dp)
{
	if(index==n || cap==0)return 0;
	if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];
	if(buy)
	{ //money has gone so assign a negative sign
		return dp[index][buy][cap]= max(- prices[index]+f(index+1,0,cap,prices,n,dp),0+f(index+1,1,cap,prices,n,dp));
	}
	else
	{
		return dp[index][buy][cap] =max(prices[index]+f(index+1,1,cap-1,prices,n,dp),0+f(index+1,0,cap,prices,n,dp));
	}
}
    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
       return f(0,1,k,prices,n,dp);   
    }
};