class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        string y=s;
       reverse(y.begin(), y.end());
        if(y==s)return true;
        else return false;
    }
};