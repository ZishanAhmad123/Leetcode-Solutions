class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>>mp;
        for(int i=0; i<size(strs); i++){
            string tmp=strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(tmp);
        }
        
      vector<vector<string>>res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};