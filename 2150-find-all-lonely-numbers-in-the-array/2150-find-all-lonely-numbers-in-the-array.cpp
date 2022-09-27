class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(auto x: nums){
            mp[x]++;
        }
        for(auto x: nums){
            if(mp[x]==1 and mp[x-1]==0 and mp[x+1]==0)
                v.push_back(x);
        }
        return v;
        
    }
};