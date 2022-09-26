class Solution {
public:
    int maxLengthAfterReplacement(string s, char ch, int k) {
        int i = 0, j = 0, maxLen=1;
        int n = s.size();
        int count = 0;
        
        while(j < n) {
            if(s[j] != ch) {
                count++;
            }
            
            while(count > k) {
                if(s[i] != ch) {
                    count--;}       
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
    
    int characterReplacement(string s, int k) {
        int maxLen = 1;
        for(int i=0;i<26;i++) {
            char ch = 'A' + i;
            maxLen = max(maxLen, maxLengthAfterReplacement(s, ch, k));
        }
        
        return maxLen;
    }
};