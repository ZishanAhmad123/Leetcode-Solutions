class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n=nums.size();
        int maxi=-1e9;
           int c1 = nums[n-1]*nums[n-2]*nums[n-3];
           int c2 = nums[0]*nums[1]*nums[n-1];
           int c3 = nums[0]*nums[n-1]*nums[n-2];
          maxi = max(c1,max(c2,c3));
            return maxi;
    }
};