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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        // we are having n*n grid
        // dots wise it is (n+1)*(n+1);
        int dots = n + 1;

        DSU dsu(dots * dots);
        // first joint all nodes on boundary of square --> as they are in one set
        for(int i = 0; i < dots; i++){
            for(int j = 0; j < dots; j++){
                if(i == 0 || j == 0 || i == dots - 1 || j == dots - 1){
                    int node = i * dots + j;
                    if(node != 0)
                        dsu.Union(0, node);
                }
            }
        }
        
        // one region for entire square
        int cnt = 1;
        
        // grid[i][j] == '/' --> (i, j + 1) , (i + 1, j)
        // grid[i][j] == '\' --> (i, j), (i + 1, j + 1)
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
              int   node1 = -1;
               int   node2 = -1;
                if(grid[i][j] == '/'){
                    node1 = i * dots + (j + 1);
                    node2 = (i + 1) * dots + (j); 
                }
                else if(grid[i][j] == '\\'){
                    node1 = i * dots + j;
                    node2 = (i + 1) * dots + (j + 1);  
                }
                
                if(node1 != -1 && node2 != -1){
                    int par1 = dsu.find(node1);
                    int par2 = dsu.find(node2);
                    if(par1 == par2)
                        cnt++;
                    dsu.Union(node1, node2);
                }
            }
        }
        
        return cnt;
    }
};