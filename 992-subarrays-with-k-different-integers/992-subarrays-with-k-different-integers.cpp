class Solution {
public:
    int atmost(vector<int>nums, int k){
        int i=0, j=0;
         if(k<=0)return 0;
        int cnt=0;
        unordered_map<int, int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
              mp[nums[i]]--;
                if(mp[nums[i]]==0)
                  mp.erase(nums[i]);
                    i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    
    
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atmost(nums, k)-atmost(nums, k-1);
    }
};