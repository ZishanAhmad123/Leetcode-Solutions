class Solution {
public:
    int minDeletions(string s) {
        
         vector<int>feq(26, 0);
        for(auto x: s) feq[x-'a']++;
        sort(feq.begin(), feq.end(), greater<int>());
        
        int allowed_feq= feq[0];
        int ans=0;
        
        for(auto x : feq){
            if(x>=allowed_feq){
                if(allowed_feq>0){
                    ans+=(x-allowed_feq);
                }else ans+=x;
            }
            allowed_feq=min(allowed_feq-1, x-1);
        }
        return ans;
    }
};