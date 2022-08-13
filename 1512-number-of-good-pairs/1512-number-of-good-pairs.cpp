class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(nums[i]==nums[j])cnt++;
        //     }
        // }
        // return cnt;
        unordered_map<int, int>mp;
        for(auto x:nums)mp[x]++;
        
        for(auto it: mp){
            if(it.second>1){
                cnt+=(it.second)*(it.second-1)/2;
            }
        }
        return cnt;
    }
};