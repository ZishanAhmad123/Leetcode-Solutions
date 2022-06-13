class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        int left = 0;
        int right = 0;
        int ans = 0;
        set<int>st;
        while (left < s.length()) {
            auto it =st.find(s[left]);
            if(it==st.end()){
                if(left-right+1>ans)
                    ans=left-right+1;
                    st.insert(s[left]);
                left++;
            }
            else{
                st.erase(s[right]);
                right++;
            }
            
        }
       
        return ans;
    }
};