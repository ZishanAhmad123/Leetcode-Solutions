class Solution {
public: 
    void FastIO(){
            ios_base::sync_with_stdio(0);cin.tie(0); }
    
    int count(int a){
     return    __builtin_popcount(a);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
         FastIO();
        
        vector<pair<int, int>>pair;
        for(int i=0; i<arr.size(); i++){
            pair.push_back({count(arr[i]), arr[i]});
        }
        sort(pair.begin(), pair.end());
        arr.clear();
        for(auto it: pair){
          arr.push_back(it.second);  
        }
        return arr;
    }
};