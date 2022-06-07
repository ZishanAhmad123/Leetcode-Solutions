class Solution {
public:
    string reverseWords(string s) {
          vector<string>v;
        string temp="",ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' ' && temp.size()){
                v.push_back(temp);
                temp="";
            }
        }
        if(temp.size()) v.push_back(temp);
        for(int i=v.size()-1;i>=1;i--){
            ans+=v[i]+" ";
        }
        ans+=v[0];
        return ans;
    }
};