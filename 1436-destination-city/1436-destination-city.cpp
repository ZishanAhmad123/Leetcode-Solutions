class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>st;
        for(auto x: paths)st.insert(x[1]);
        
        for(auto x: paths){
            if(st.find(x[0])!=st.end())
                st.erase(x[0]);
        }
        for(auto s: st){
            return s;
        }
        return "";
    }
};