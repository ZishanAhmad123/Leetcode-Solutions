class Solution {
public:
      long long f ( vector<vector<int>>& questions , int i,  vector<long long>&dp){
        //base cases
        
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long op1 = INT_MIN, op2 = INT_MIN;
        
        op1 = (long long)questions[i][0] + f(questions, i+ questions[i][1] + 1 , dp);
        op2 = (long long) f(questions, i + 1, dp);
        return dp[i] = max(op1,op2);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
       
           vector<long long>dp(100007,-1);
           return f(questions, 0, dp); 
    }
};