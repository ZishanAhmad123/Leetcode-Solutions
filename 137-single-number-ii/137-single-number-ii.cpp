class Solution {
public:
   
    int singleNumber(vector<int>& nums) {
         int x1 = 0, x2 = 0, x3 = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            x3 ^= x2 & nums[i];
            x2 ^= x1 & nums[i];
            x1 ^= (~x2) & nums[i];
        }
        
        return x1;
          }
};