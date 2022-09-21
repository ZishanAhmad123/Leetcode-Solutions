class Solution {
public:
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
    
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        
        DSU dsu(n/2);
		
		//for each person we define it's couple id as person/2 i.e., [0,1]-->0 [2,3]-->1 [4,5]-->2 and so on..
        for(int i=0;i<n;i+=2)
        {
            dsu.Union(row[i]/2,row[i+1]/2);
        }
        
        int res=0;
        set<int>parents;
        for(int i=0;i<n;i++)
        {
            parents.insert(dsu.find(row[i]/2));
        }
        
        for(auto &p:parents)
            res+=dsu.size[p]-1;
        return res;
    }
};