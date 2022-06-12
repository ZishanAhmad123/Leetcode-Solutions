class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int>mp;
        int sum=0, j=0;
        int ans=INT_MIN;
        for(int i=0; i<nums.size(); i++){
         sum+=nums[i];
          mp[nums[i]]++;

          while(i-j+1!=mp.size()){
             sum-=nums[j];
              mp[nums[j]]--;
              if(mp[nums[j]]==0)
                  mp.erase(nums[j]);
              j++;
          }
         ans=max(ans, sum);
    }
    return ans;
    }
};