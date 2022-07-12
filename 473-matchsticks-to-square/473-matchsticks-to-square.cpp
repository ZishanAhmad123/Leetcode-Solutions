class Solution {
public:
    bool makesquare(vector<int>& match) {
        int sum = accumulate(match.begin(),match.end(),0);
        if(sum%4) return false;
        sum/=4;
        
        int n= match.size();
        
         int dp[(1<<16)+2];
         fill(dp, dp+(1<<16)+2, -1);
         dp[0] = 0;
         
         for (int mask = 0; mask < (1<<n); mask++) 
         {
             if (dp[mask] == -1) continue; 
             for (int i = 0; i < n; i++) 
             {
                if (!(mask&(1<<i)) && dp[mask]+match[i] <= sum) 
                {  
                    dp[mask|(1<<i)] = (dp[mask]+match[i]) % sum;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};