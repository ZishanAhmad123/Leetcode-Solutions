class Solution {
public:
    
    int trapRainWater(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
    
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){           // boundry not contain water so visited them  already
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
				    pq.push({grid[i][j] , {i,j}}) ;
					vis[i][j]=true;
					}
            }
        }
           
        int total=0;
        int minBdht=0;        
        while(!pq.empty())       // bfs multivalued
        {
            int currHeight = pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            
            minBdht = max( currHeight , minBdht);
            
            int dx[4]={0,0,-1,1};
            int dy[4]={1,-1,0,0};
            
            for(int i=0;i<4;i++)
            {
                int newX = x+dx[i];
                int newY = y+dy[i];
                
                if(newX>=0 && newX<n && newY>=0 && newY<m && !vis[newX][newY] )  // edgecase of bfs
                {
                       pq.push({grid[newX][newY] , {newX , newY}});
                       vis[newX][newY]=true;
                       if(grid[newX][newY] < minBdht)
                        total += (minBdht-grid[newX][newY]);          
                }
                
            }
            
        }
        return total;
    }
};