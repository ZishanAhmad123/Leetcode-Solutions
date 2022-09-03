class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       map<int,int> m;
        int sum=0;
       m.insert({0,-1});
        
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(m.count(sum%k) && i-m[sum%k]>1)return 1;
            else if(!m.count(sum%k))
                m[sum%k]=i;
        }
        
        return 0;
    }
};