class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        
        priority_queue < pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>      > pq;
        int dist[m][n];
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++)
                dist[i][j] = INT_MAX;
        
        dist[0][0] =grid[0][0];
        
        int dx[] = {0,0,1,-1};
        int dy[]=  {1,-1,0,0};
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()) {
            auto cur = pq.top();
            int cost = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            vis[x][y] = 1;
            pq.pop();
            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny]) continue;
                if(dist[nx][ny] > grid[nx][ny] + dist[x][y]) {
                    dist[nx][ny] = grid[nx][ny] + dist[x][y];
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};