class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=indices.size();
        string ans="";
        unordered_map<int,string> tar,src;   // mapping indices to string
        for(int i=0;i<n;i++){
            tar[indices[i]]=targets[i];
            src[indices[i]]=sources[i];
        }
       unordered_set<int> iset(indices.begin(),indices.end());
        int i=0;
        while(i<s.length()){
            if(iset.find(i)!=iset.end()){
                string temp=src[i];
                int len=temp.length();
                if(!temp.compare(s.substr(i,len))){
                    ans+=tar[i];
                    i+=len;
                }
                else{
                    ans+=s[i];
                    i++;
                }
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
    
};