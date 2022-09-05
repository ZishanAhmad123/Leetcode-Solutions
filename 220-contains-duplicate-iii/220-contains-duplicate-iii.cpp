class Solution {
public:
    #define ll long long int
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<ll,int>> vt;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            vt.push_back({nums[i],i});
        }
        sort(vt.begin(),vt.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n&&abs(vt[i].first-vt[j].first)<= t;j++)
            {
                if(abs(vt[i].second - vt[j].second) <= k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};