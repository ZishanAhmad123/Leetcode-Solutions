class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt=0;
        //  for(int i=0; i<nums.size(); i++){
        //      int sum=0;
        //      for(int j=i+1; j<nums.size(); j++){
        //          sum+=nums[i]+ nums[j];
        //          if(sum==k)cnt++;
        //      }
        //  }
        // return cnt;
        int n=size(nums);
        if(n==0)return 0;
        int Cursum=0, i=0, cnt=0;
       unordered_map<int, int>mp;
       for(int i=0; i<nums.size(); i++){
            Cursum+=nums[i];
            if(Cursum==k)cnt++;
            
            if(mp.find(Cursum-k)!=mp.end()){
                cnt+=mp[Cursum-k];
            }
                mp[Cursum]++;
            
        }
        return cnt;
    }
};