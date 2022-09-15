class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++)
        {
            v.push_back({values[i],labels[i]});
        }
        sort(v.begin(),v.end());
        
        unordered_map<int,int> mp;
        int ans = 0;
        int cnt = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(cnt==numWanted)return ans;
            if(mp[v[i].second]+1<=useLimit)
            {
                ans += v[i].first;
                cnt++;
                mp[v[i].second]++;
            }
        }
        return ans;
    }
};