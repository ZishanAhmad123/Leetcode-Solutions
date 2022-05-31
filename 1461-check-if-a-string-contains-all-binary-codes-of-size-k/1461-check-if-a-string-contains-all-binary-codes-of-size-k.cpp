class Solution {
public:
    bool hasAllCodes(string s, int k) {
      unordered_set<string>st;
        string w=s.substr(0,k);
        st.insert(w);
        
        for(int i=k;i<s.size();i++){
           w=w.substr(1)+s[i];
            st.insert(w);
        }
        
        return (st.size()==(pow(2,k)));   
    }
};