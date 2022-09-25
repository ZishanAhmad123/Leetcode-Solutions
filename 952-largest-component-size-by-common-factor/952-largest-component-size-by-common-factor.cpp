class DSU
    {
        public:
        vector<int>par,size;
        DSU(int n)
        {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        
        int find(int x)
        {
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }
        
        bool Union(int a,int b)
        {
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)return 1;
            
            if(size[pa]>size[pb])
            {
                par[pb]=pa;
                size[pa]+=size[pb];
            }
            else
            {
                par[pa]=pb;
                size[pb]+=size[pa];
            }
            return 0;
        }
    };
class Solution {
public:
    
    int largestComponentSize(vector<int>& nums) {
       int maxNum = *max_element(nums.begin(), nums.end());
        DSU dsu(maxNum + 1);
    
         for(int i=0; i<nums.size(); ++i){
            for(int j=2; j<=sqrt(nums[i]); ++j){       // connecting all factor of nums[i] to num[i] in one grp 
                if(nums[i]%j==0){
                    dsu.Union(nums[i], j);
                    dsu.Union(nums[i]/j, j);
                }
            }
        }
        
        unordered_map<int,int>mp; 
        int n=nums.size();
        int maxi=1;
        for(int i = 0; i < n; i++)
        {
            int x_par = dsu.find(nums[i]);
            mp[x_par]++;
            maxi = max(maxi, mp[x_par]);
        }
        
        return maxi;
    }
};