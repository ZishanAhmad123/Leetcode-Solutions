class Solution {
public: int getFirstSetBit(int n){
        if(n==0)return 0;
         int cnt=0;
        while(n){
            if(n&1){
             break;
            }
           cnt++;
            n=n>>1;
        }
        return cnt;
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i=0; i<nums.size(); i++){
            xr=xr^nums[i];
        }
       int cnt=getFirstSetBit(xr);
        int xor1=0, xor2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&(1<<cnt)){
                xor1=xor1^nums[i];
            }
            else 
                xor2=xor2^nums[i];
             }
        return {xor1, xor2};
    }
};