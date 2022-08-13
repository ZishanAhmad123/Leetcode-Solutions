class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
            int n = words.size();
        int len = words[0].size();
        int size = s.size();
        vector<int> ans;
        
        unordered_map<string, int> mp, temp;
        
        for(string &str : words) {
            mp[str]++;
        }
        
        for(int i=0; i<size-(n*len)+1; i++) {
            
            for(int j=i; j<i+n*len; j+=len) {
                string str = s.substr(j, len);
                temp[str]++;
            }
            if(mp == temp) {
                ans.push_back(i);
            }
            temp.clear();
        }
        return ans;}
};