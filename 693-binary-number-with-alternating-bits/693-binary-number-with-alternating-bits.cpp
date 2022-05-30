class Solution {
public:string to_binary(int x){
  string binary;
    while(x){
        binary.push_back(x%2 + '0');
        x/=2 ;}return binary;}
    
    bool hasAlternatingBits(int num) {
        string s=to_binary(num);
        for(int i=0; i<s.size(); i++){
            if(s[i]==s[i+1])return false;
        }
        return true;
    }
};