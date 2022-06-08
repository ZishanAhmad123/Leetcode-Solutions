class Solution {
public:
    bool isPalindrome(string S)
{string P = S; reverse(P.begin(), P.end());if (S == P) {return true;}else {return false; }} 
    
    int removePalindromeSub(string s) {
        if(isPalindrome(s))return 1;
        else return 2;
    }
};