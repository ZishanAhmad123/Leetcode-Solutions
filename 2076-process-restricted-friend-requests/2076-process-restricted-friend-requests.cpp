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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
          DSU dsu(n+1);     
        vector<bool> ans;
        
        for(auto &it: requests){
            int x = it[0];
            int y = it[1];
            
            DSU temp = dsu;     // nice updating
            
            temp.Union(x, y);
            
            bool flag = true;
            for(auto &itr: restrictions){
                int x1 = itr[0];
                int y1 = itr[1];
                
                if(temp.find(x1)==temp.find(y1)){
                    flag=false; 
                    break;
                }
            }
            
              if(flag){ 
                dsu.Union(x, y);  // successful accepted
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        
        return ans;
    }
};