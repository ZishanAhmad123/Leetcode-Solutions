class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
           int n=nums.size();  
          int prev=0;
          int ans=1;
        
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            if(diff !=0){
              if(diff*prev<=0)
                ans++; 
                
               prev=diff;
            }
            
        }
        return ans;
    }
};