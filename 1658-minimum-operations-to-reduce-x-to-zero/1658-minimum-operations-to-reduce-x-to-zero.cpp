class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int n=size(nums);
        if(n==0)return -1;
         int sum=0; unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        if(x>sum)return -1;
        sum =sum -x;                  // subarry sum equal to sum -x   lets say k
        int k=sum;                   // now this is problem of longest subaaray sum equal to k\U0001f60a\U0001f60a
        int Cursum=0,  longest=0;
           mp[0]=0;
        
       for(int i=0; i<nums.size(); i++){
            Cursum+=nums[i];
            if(mp.find(Cursum-k)!=mp.end()){
               if(Cursum-k==0){
                   longest=max(longest, i-mp[Cursum-k]+1);
               }
                else longest= max(longest, i-mp[Cursum -k]);
            }  
        }
        return longest==0?(k==0?nums.size(): -1): nums.size()-longest;
    }
};