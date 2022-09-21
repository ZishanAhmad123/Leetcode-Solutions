class Solution {
public:
    int minSwaps(vector<int>& nums) {
         int cnt=0;
        for(auto N:nums){
            if(N==1) cnt++;
        }
        
        //in case array is all 0's, return ans as 0
        if(cnt == 0) return 0;
        
        //2. append the nums array to itself
        nums.insert(nums.end(), nums.begin(), nums.end());
         int len=nums.size();
        int i=0,j=0,swapCnt=0;
        int minSwap=INT_MAX;
        
        while(j<len){
            
            swapCnt += nums[j] == 0 ? 1 : 0;
            //if window is less than window size
            if(j-i+1 < cnt) j++;
            
            else if(j-i+1 == cnt){
                minSwap = min(minSwap,swapCnt); //update ans
                
                if(nums[i]==0) swapCnt--;//update the count of zeros
                
                i++;
                j++;
                
            }
        }
        
      return minSwap;  
    }
};