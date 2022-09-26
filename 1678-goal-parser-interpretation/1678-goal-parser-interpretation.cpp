class Solution {
public:
    string interpret(string str) {
         int length = str.size();
        string ans="";
        int i=0;
        while(i<=(length-1)){
            if(str[i]=='('  and str[i+1]==')'){
                 ans.append("o");
                i=i+2;
            }
            else if (str[i]=='G'){
                ans.append("G");
                i++;
            }
            else{
                ans.append("al");
                i=i+4;
            }
        }
        
        return ans;
    }
};