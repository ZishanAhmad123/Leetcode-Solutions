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
    int countServers(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        DSU dsu(m * n);
		// union servers on the same ROW
        for (int i = 0; i < m; i++) {
            int j = 0;
            for (; j < n and grid[i][j] == 0; j++) ;
            for (int k = j + 1; k < n; k++)
                if (grid[i][k])
                    dsu.Union(i * n + j, i * n + k);
        }
		// union server on the same COLUMN
        for (int j = 0; j < n; j++) {
            int i = 0;
            for (; i < m and grid[i][j] == 0; i++) ;
            for (int k = i + 1; k < m; k++)
                if (grid[k][j])
                dsu.Union(i * n + j, k * n + j);
        }
        unordered_map<int, int> count;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
				// is a server and parent is not itself
                if (grid[i][j] and dsu.find(i * n + j) != i * n + j) {
                    count[dsu.find(i * n + j)]++;
                }
            }
        }
        int res = 0;
        for (const auto& it : count)
            res += it.second + 1;  // don't forget the parent
        return res;
    }
};