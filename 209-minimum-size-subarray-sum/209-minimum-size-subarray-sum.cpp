class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,sum=0,minLen=1e6;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(start<=i && sum>=target){
                minLen=min(minLen,i-start+1);
                sum-=nums[start];
                start++;
            }
        }
        if(minLen==1e6)return 0;
        return minLen;
    }
};