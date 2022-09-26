
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& q) {
        
        DSU dsu(n+1);
		 for(int i=1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                if(i>threshold)
                    dsu.Union(i,j);
            }
        }   
        
        vector<bool>v;
        for(auto x: q){
            if(dsu.find(x[0])==dsu.find(x[1]))v.push_back(true);
            else v.push_back(false);
        }
        return v; 
    }
};