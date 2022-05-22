class Solution {
public:
   int solve(string s, int i, int j){
        int res = 0;
        while(i >= 0 && j <= s.size() && s[i] == s[j]){
            ++res; --i; ++j;
        }
        return res;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            ans += solve(s, i, i);
            ans += solve(s, i, i + 1);
        }
        return ans;
        
    }
};