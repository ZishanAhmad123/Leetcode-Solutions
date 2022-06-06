class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<int>v;
        for(auto x: nums)mp[x]++;
        for(auto it: mp){
            if(it.second==2){
                v.push_back(it.first);
            }
        }
        return v;
    }
};