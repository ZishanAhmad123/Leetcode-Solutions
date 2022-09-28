class Solution {
public:
    vector<int> Dijkstra(int src,  vector<vector<pair<int, int>>>&graph, int V) {
      vector<int> distanceToLastNode(V+1, 1e9);
    distanceToLastNode[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.push({0, src});
      while (!pq.empty()) {
           int u=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            /* TLE Elimination */
            // if(distance>distanceToLastNode[u])
            //     continue;
      for (auto next : graph[u]) {
        int v = next.first, dis = next.second;
        if (distanceToLastNode[v] > distanceToLastNode[u] + dis) {
          distanceToLastNode[v] = distanceToLastNode[u] +dis;
          pq.push({distanceToLastNode[v], v});
        }
      }
    }
        return distanceToLastNode;
  }
    
    int minCost(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
  
        vector<vector<pair<int,int>>>adj(m*n+1); // making graph
        
        int dif[]={0,1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                     int r=i+dif[k],c=j+dif[k+1];
                     if(r>=0 && r<n && c>=0 && c<m){
                        // According to the direction we will deside the cost
                        if((grid[i][j]==1 && k==0)|| (grid[i][j]==2 && k==2) || (grid[i][j]==3 && k==1) || (grid[i][j]==4 && k==3)){
                            adj[i*m+j].push_back({r*m+c,0});
                        }else{
                            adj[i*m+j].push_back({r*m+c,1});
                        }
                    }
                }
            }
        }
        
        // Applying Dijkstra's 
        vector<int>dist(m*n+1,1e9);
        dist=Dijkstra(0, adj, n*m);
        return dist[n*m-1];

        
    }
};