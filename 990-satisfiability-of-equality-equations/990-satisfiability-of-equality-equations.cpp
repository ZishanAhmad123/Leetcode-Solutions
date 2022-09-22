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
    }
};
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(27);
        for(auto e: equations){
            if(e[1]=='='){
                dsu.Union(e[0]-'a', e[3]-'a');
            }
        }
        
        for(auto e: equations){
            if(e[1]=='!'){
                int p1=dsu.find(e[0]-'a');
                int p2=dsu.find(e[3]-'a');
                if(p1==p2)return false;
            }
        }
    return true   ; 
    }
};