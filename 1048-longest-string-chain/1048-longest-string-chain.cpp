class Solution {
public:
      map<string,int> mp,dp;
     static bool cmp(const string &a,const string &b){
        return a.length()>b.length();
    }
    int f(string &s){
       if (s.length()<=0){
           return 0;
       } 
       if (dp[s])
           return dp[s];
       
       int val=0;
        
       for (int j=0; j<s.length(); j++){
           string a=s.substr(0,j);
           string b=s.substr(j+1);
           
           a+=b;
           
           if (mp.find(a)!=mp.end()){
               val=max(val,1+f(a));
           }
       }
     return dp[s]=val;
        }
    
    
    int longestStrChain(vector<string>& v) {
         sort(v.begin(),v.end(),cmp);
        
        for ( int i=0; i<v.size(); i++)
            mp[v[i]]++;
             dp.clear();
            
            int ans=0;
        for ( int i=v.size()-1; i>=0; i--){
            ans=max(ans,1+f(v[i]));
        }
     return ans;
        }
    
};