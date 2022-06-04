class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
       //  string y=s;
       // reverse(y.begin(), y.end());
       //  if(y==s)return true;
       //  else return false;
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            else{
                i++;j--;
            }
        }
        return true;
    }
};