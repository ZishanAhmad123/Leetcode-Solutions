class Solution {
public:
    int candy(vector<int>& nums) {
        int n=size(nums);
    vector<int>ans(n,1);
    for(int i=1;i<n;i++)
    {
        if(nums[i]>nums[i-1] )
        {
            ans[i]=ans[i-1]+1;
            
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]>nums[i+1] and ans[i]<=ans[i+1])
        {
            ans[i]=ans[i+1]+1;
        }
    }
    int sum=0;
        for(auto x : ans)sum+=x;
        return sum;
    }
};