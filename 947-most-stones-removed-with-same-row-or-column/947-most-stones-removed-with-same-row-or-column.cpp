class Solution {
public:
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
    }                        // DSU dsu(27) in case of alphabet
};
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
    
        DSU dsu(n);
        
        for(int i = 0; i<stones.size(); i++){
            for(int j = i+1; j<stones.size(); j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                dsu.Union(i,j);
                }
            }
        }
        
        unordered_set<int>us;
        for(int i = 0; i<stones.size(); i++){
            us.insert(dsu.find(i));
        }
        
        
        return stones.size()-us.size();
    }
};