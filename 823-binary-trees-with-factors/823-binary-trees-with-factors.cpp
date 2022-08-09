class Solution {
public:
    #define mod 1000000007
    #define ll long long
     ll dp[1001];
    unordered_map<long long,long long> mp;
    
    ll solve(int root,vector<int>& arr)
    {
        if(dp[root]!=0)return dp[root];
        ll cnt=1;
        for(int i=0;i<root;i++)
        {
            if((arr[root]%arr[i])==0){
                int t1=arr[i];
                int t2=arr[root]/arr[i];
              if(mp.find(t2)!=mp.end())
              {
                  cnt+=(solve(i,arr)%mod*solve(mp[t2],arr)%mod)%mod;
              }
            }
        }
        return dp[root]=cnt;
       
        
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        memset(dp,0,sizeof(dp));
           sort(arr.begin(),arr.end());
        int n=arr.size();
      for(int i=0;i<n;i++)mp[arr[i]]=i;
        ll ans=0;
        for(int i=0;i<arr.size();i++)
        {
            ans=(ans%mod+solve(i,arr)%mod)%mod;
        }
        return ans;

        
    }
};