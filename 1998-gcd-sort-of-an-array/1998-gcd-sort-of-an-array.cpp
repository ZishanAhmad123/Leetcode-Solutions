class DSU{
    vector<int> par,rank;
    int n;
    public:
    DSU(int n)
    {
        this->par.resize(n);
        this->rank.resize(n);
        this->n=n;
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    int find(int x)
    {
        if(x==par[x])return x;
        return par[x]=find(par[x]);
    }
    void Union(int a, int b)
    {
        int a_par=find(a);
        int b_par=find(b);
        if(a_par==b_par)
            return;
        if(rank[a_par]<rank[b_par])
        {
            par[a_par]=b_par;
        }
        else if(rank[b_par]<rank[a_par]){
            par[b_par]=a_par;
        }
        else
        {
            par[a_par]=b_par;
            rank[b_par]+=1;
        }
    }
};
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        int n = *max_element(nums.begin(), nums.end());
         DSU dsu(n+1);
        for(int i=0; i<nums.size(); ++i){
            for(int j=2; j<=sqrt(nums[i]); ++j){
                if(nums[i]%j==0){ 
                    dsu.Union(nums[i],j);
                    dsu.Union(nums[i],nums[i]/j);
                }
            }
        }
        
        for(int i=0; i<nums.size(); ++i){
            if(dsu.find(nums[i]) != dsu.find(nums2[i])) return false;
        }
        return true; 
    }
};