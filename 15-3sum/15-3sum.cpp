class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
       int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            int low = i+1, high = n-1;
            while(low < high){
                vector<int> ans(3,0);
                if(nums[low]+nums[high] == -nums[i]){
                    ans[0] = nums[i];
                    ans[1] = nums[low];
                    ans[2] = nums[high];
                    res.emplace_back(ans);
                    
                    while(low < high && nums[low] == nums[low+1]) low++;                //    --(1)
                    while(high > low && nums[high] == nums[high-1]) high--;              //   --(2)
                    
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high] > -nums[i]){
                    high--;
                }
                else if(nums[low]+nums[high] < -nums[i]){
                    low++;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};