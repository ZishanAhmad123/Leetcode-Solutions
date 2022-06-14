class Solution {
public:
     int isPalindrome(const std::string& s, int left, int right)
    {
        int pal_len = right - left + 1;
        while (left <= right){
            if (s[left] != s[right])
                return -1;
            left++;
            right--;
        }
        return pal_len;
    }
    string longestPalindrome(string s) {
        // string res;
        // for (int left = 0; left < s.length(); left++)
        // {
        //     for (int right = left; right < s.length(); right++)
        //     {
        //         int pal_len = isPalindrome(s, left, right);
        //         if (pal_len != -1 && pal_len > res.length())
        //         {
        //             res = string(s.begin() + left, s.begin() + right + 1);
        //         }
        //     }
        // }
        // return res;
        
        
        
         int n = s.length();
        string res = "";
        int resLen = 0;
        int l,r;
        for(int i=0;i<n;i++){
            //odd length
            l = i; r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>resLen){
                    res = s.substr(l,r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
            
            //even length
            l=i; r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>resLen){
                    res = s.substr(l,r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }
        
        return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};