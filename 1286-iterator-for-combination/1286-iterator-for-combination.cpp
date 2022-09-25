class CombinationIterator {
public:map<string, int>mp;
    map<string, int>::iterator ptr;
    CombinationIterator(string s, int cl) {
        int n=s.size();
        for(int i=1; i<(1<<n); i++){
            string ans="";
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    ans.push_back(s[j]);
                }
            }
            if(ans.size()==cl)
                    mp[ans]++;
        }
         ptr=mp.begin();
    }
    
    string next() {
        auto temp=ptr;
        ptr++;
        return temp->first;
    }
    
    bool hasNext() {
        return ptr!=mp.end()?true: false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */