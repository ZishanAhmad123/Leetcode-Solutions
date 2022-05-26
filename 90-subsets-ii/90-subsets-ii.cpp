class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>subset_all;
        set<vector<int>>s;
        
        for(int mask=0; mask< 1<<nums.size(); mask++){
            vector<int>subset;
            for(int i=0; i<nums.size(); i++){
                if(mask&(1<<i))
                    subset.push_back(nums[i]);
            }
            sort(subset.begin(), subset.end());
            s.insert(subset);
            subset.clear();
        }
        
        for(auto it: s){
            subset_all.push_back(it);
        }
        return subset_all;
        
    }
};