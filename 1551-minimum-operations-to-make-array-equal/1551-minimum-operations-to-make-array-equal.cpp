class Solution {
public:
    int minOperations(int n) {
        
        vector<int>nums;
        int temp=0;
        for(int i=0; i<n; i++){
            temp+=(2*i)+1;
             nums.push_back((2*i)+1);
        }
        int t=temp/n;
       int res=0;
     for(int i=0;i<n;i++){
          if(t-nums[i]>=0)
        res+=t-nums[i];
      }
      return res;
        
        
    }
};