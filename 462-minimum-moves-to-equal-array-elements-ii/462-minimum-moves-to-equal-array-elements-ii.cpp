class Solution {
public:
    int minMoves2(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        
        int l = 0, r = size(nums) - 1;
        int mid =  (l + r)/2;
        int mid_val = nums[mid];
        
        int sum = 0;
        for (int i=0; i<nums.size(); i++) 
            sum+= abs(mid_val - nums[i]);
        
        return sum;
    }
};