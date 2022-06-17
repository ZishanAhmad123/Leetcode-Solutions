class Solution {
public:
    int minCost(string s, vector<int>& v) {
         
       int ans = 0;
        char preColor = s[0];
        int preTime = v[0];
        
        for(int i=1; i<s.length(); i++) {
            if(s[i] == preColor) {
                ans += min(preTime, v[i]);     // Will delete balloon with minimum time
                preTime = max(preTime, v[i]); // As balloon with minimum time is deleted, our variable will store maximum time
            }
            else {
                preColor = s[i];
                preTime = v[i];
            }
        }
        return ans;
    }
};