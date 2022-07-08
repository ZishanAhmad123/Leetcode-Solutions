class Solution {
public:
int dp[100][100][101];
int f(int i,int l,int t,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
if(i == m){
return (t == target)?0:1e9;
}
if(dp[i][l][t] != -1)return dp[i][l][t];
else{
int ans = 1e9;
if(houses[i] == 0){
for(int j =0;j <n;j++){
ans = min(ans,cost[i][j]+f(i+1,j+1,(l==j+1)?t:t+1,houses,cost,m,n,target));
}
}
else{
ans = min(ans,f(i+1,houses[i],(houses[i] == l)?t:t+1,houses,cost,m,n,target));
}
return dp[i][l][t] = ans;
}
}
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    memset(dp,-1,sizeof dp);
    int ans = f(0,0,0,houses,cost,m,n,target);
    return ans==1e9?-1:ans;
    }
};