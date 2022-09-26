
class Solution {
public:
    bool  bipartite(unordered_map<int,vector<int>> &graph,  vector<int>&color,int node){
      if(color[node]==-1)color[node]=1;
      for(auto child: graph[node]){
          if(color[child]==-1){
              color[child]=1-color[node];
              if(!bipartite(graph , color,child)) return false;
             
          } else if(color[node]==color[child])return false;
      }
      return true;
  }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
      unordered_map<int,vector<int>> adj;
        for(int i=0;i<dislikes.size();i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(adj,color,i)) return false;
            }
        }
        return true;
   
    }
};