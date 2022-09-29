class DSU
    {
        public:
        vector<int>par,size,rank;
        DSU(int n)
        {
            par=vector<int>(n);
            size=vector<int>(n,1);
            rank=vector<int>(n,1);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        
        int find(int x)
        {
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }
        
//        bool Union(int a,int b)
//         {
//             int pa=find(a);
//             int pb=find(b);
//             if(pa==pb)return 1;
            
//             if(size[pa]>size[pb])
//              {
//                 par[pb]=pa;
//                 size[pa]+=size[pb];
//             }
//             else
//             {
//                 par[pa]=pb;
//                 size[pb]+=size[pa];
//             }
//             return 0;
//         }
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] >= rank[rootY]) {
            par[rootY] = rootX;
        } else {
            par[rootX] = rootY;
        }
    }
        
    };

class Solution
{
    public:
     bool isValid(int x, int y,int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    int dfs(int x, int y, DSU &uf, int par, vector<vector<int>>& grid,vector<vector<bool>> &visited) {
        int n=grid.size();
        int m=grid[0].size();
        uf.Union(par, x * m + y);
        int cnt = 1;
        visited[x][y] = true;
         int d[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int u = x + d[i];
            int v = y + d[i + 1];
            if (isValid(u, v,n,m) && grid[u][v]==1 && !visited[u][v]) {
                 cnt += dfs(u, v, uf, par, grid, visited);
            }
        }
        return cnt;
    }
     
    int largestIsland(vector<vector < int>> &grid)
    {
       
      unordered_map<int, int> mp;
      int  n = grid.size();
      int  m = grid[0].size();
      
      vector<vector<bool>> visited(n,vector<bool>(m,false));  
		
        DSU dsu(n * m);
      
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] == false && grid[i][j]) {
                    int cnt = dfs(i, j, dsu, i * m + j, grid,visited);
                     mp[i * m + j] = cnt;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    int curr = 0;
                    int d[] = {-1, 0, 1, 0, -1};
                    set<int> s;
                    for (int k = 0; k < 4; ++k) {
                        int u = i + d[k];
                        int v = j + d[k+1];
                        if (isValid(u, v, n ,m)) {
                            int par = dsu.find(u * m + v);
                            s.insert(par);
                        }
                    }
					for (auto a: s) {
						curr += mp[a];
					}
                    ans = max(ans, curr + 1);
                }
            }
        }
		//If the answer remains 0, that means, there was no zero in the matrix.
        return (ans == 0? n * m: ans);
    }
};