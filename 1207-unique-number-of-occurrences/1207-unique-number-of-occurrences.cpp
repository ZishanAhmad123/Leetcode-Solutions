class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         unordered_map<int, int> freq;
        set<int> s;
        
        for(const int& val : arr)
            freq[val]++;
        
        for( auto& p : freq){
            if(s.count(p.second))                // if freq of element is already present in set return false else insert krdo
                return false;
            s.insert(p.second);
        }
        return true;
    }
};