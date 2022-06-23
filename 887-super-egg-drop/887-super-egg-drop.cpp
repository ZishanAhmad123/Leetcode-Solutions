class Solution {
public:
     
   int f(int k,int n,vector<vector<int>>& dp)
    {
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int l=1,r=n,ans=1e9;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int left=f(k-1,mid-1,dp);
            int right=f(k,n-mid,dp); 
            int temp=1+max(left,right);
             if(left<right) 
                l=mid+1;
            else           
                r=mid-1;
            ans=min(ans,temp);
        }
        return dp[n][k]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f( k, n, dp);
    }
};