class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flip=0;
        int ans=0;
        int i=0, j=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==0)flip++;
            while(flip>k){
                if(nums[j]==0)flip--;
                j++;
            }
            ans=max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};