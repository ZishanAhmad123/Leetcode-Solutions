class Solution {
public:
    string greatestLetter(string s) {
        
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        
        sort(s.begin(), s.end());  
        string str = "";
        for(int i=0; i<s.size(); i++){
            
            char l = tolower(s[i]);
            char u = toupper(s[i]);
            // cout<<l<<" "<<u<<endl;
            
            if(mpp[l] && mpp[u]){  
                str = u;
            }     
        }
        
        return str;
    }
};