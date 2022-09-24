class Solution {
public:
    string findstring(int i){
        if(i==1)return "0";
        string s=findstring(i-1);
        string ans=s+'1';
        for(int j=0; j<s.size(); j++){
            if(s[j]=='1')s[j]='0';
            else s[j]='1';
        }
        reverse(s.begin(), s.end());
        ans+=s;
        return ans;
    }
    char findKthBit(int n, int k) {
        string s=findstring(n);
        return s[k-1];
    }
};