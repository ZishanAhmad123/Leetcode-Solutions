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
    bool hasValidPath(vector<vector<int>>& g) {
          int n = g.size();
        int m = g[0].size();
        
       DSU dsu(n*m+1);
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                int x = i, y = j;
                for(int k = 0; k < 4; k++) {
                    int nx =  x + dx[k];
                    int ny = y + dy[k];
                    
                    
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m)
                        continue;
                    int way = g[nx][ny];
                    int curr = g[x][y];
                    
                    // top
                    if(k == 0) {
                        if(curr == 5 or curr == 6 or curr == 2) {
                            if(way == 2 or way == 3 or way == 4)
                                dsu.Union(x * m + y, nx * m + ny);
                        }  
                    }
                    // right
                     if(k == 1) {
                         if(curr == 1 or curr == 4 or curr == 5) {
                            if(way == 3 or way == 5 or way == 1)
                                dsu.Union(x * m + y, nx * m + ny);
                        }
                     }
                    // down
                    if(k == 2) {
                        if(curr == 3 or curr == 4 or curr == 2) {
                            if(way == 2 or way == 5 or way == 6)
                                dsu.Union(x * m + y, nx * m + ny);
                        }
                    }
                    // left
                    if(k == 3) {
                        if(curr == 3 or curr == 5 or curr == 1) {
                            if(way == 4 or way == 6 or way == 1)
                                dsu.Union(x * m + y, nx * m + ny);
                        }
                    } 
                }   
                // if (0, 0) and (n - 1, m - 1) are connected too return true
                if(dsu.find(0) == dsu.find(n * m - 1))
                    return true;
            }
        }
        return false;
    }
};