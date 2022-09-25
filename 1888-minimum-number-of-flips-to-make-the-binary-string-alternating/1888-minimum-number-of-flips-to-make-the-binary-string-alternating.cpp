class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        s += s;
        string s1,s2;
        for(int i=0; i<s.length(); i++){
            
            s1 += i%2 ? '0':'1';
            s2 += i%2 ? '1':'0';
        }
        int diff1=0 , diff2=0 , ans=INT_MAX;
        for(int i=0; i<s.length(); i++){
             if(s[i]!=s1[i])
                 ++diff1;
             if(s[i]!=s2[i])
                 ++diff2;
            if(i>=n){
                if(s[i-n]!=s1[i-n])
                  --diff1;
                if(s[i-n]!=s2[i-n])
                  --diff2;
            }
            if(i>=n-1)
                ans=min({ans,diff1,diff2});
        }
        return ans;
    }
};