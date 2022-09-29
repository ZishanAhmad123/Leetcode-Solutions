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
bool comp(vector<int> &a,vector<int> &b){
    if(a[2] == b[2]){
        return a[1]<b[1];
    }
    return a[2]<b[2];
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n+1);
         int m = queries.size();
        for(int i=0;i<queries.size();i++) {
            queries[i].push_back(i);             // store q indices
        }
        
        sort(queries.begin(),queries.end(),comp);
        sort(edges.begin(),edges.end(),comp);
        
        vector <bool> ans(queries.size(),false);
        int idx = 0;
        for(int i = 0; i<queries.size(); i++){
            // Here we loop on edges vector and join the two nodes having dist < curr_limit.
			while(idx<edges.size() and edges[idx][2]<queries[i][2]){
                dsu.Union(edges[idx][0],edges[idx][1]);
                idx++;
            }
			// If the two nodes of current query has same godfather, we set this queries ans as true
            if(dsu.find(queries[i][0]) == dsu.find(queries[i][1])) ans[queries[i][3]] = true;
        }
        return ans;
    }
};