class Solution {
public:   bool check(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s==t)return true;
    else return false;
}
    
    bool isAnagram(string s, string t) {
    if(check(s, t))
        return true;
        else return false;
    }
};