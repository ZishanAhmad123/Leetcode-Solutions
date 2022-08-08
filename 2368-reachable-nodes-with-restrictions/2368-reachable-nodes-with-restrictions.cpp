class Solution {
public:
     void dfs(int node,int &cntnode, vector<vector<int>>&adj, vector<int>&vis){
        vis[node]=true;
          cntnode++;
        for(auto child:adj[node]){
             if(!vis[child] ){
                 dfs(child,cntnode,adj,vis);
             }
        }
        
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        
        vector<vector<int>>adj(n);
        int cnt = 0;
        map<int, int>mp;
        for(int i = 0;i < edges.size();i++){     // adjacency list
            int u=edges[i][0];int v=edges[i][1];
             adj[u].push_back(v); adj[v].push_back(u); 
            
        }
        vector<int>vis(n, false);
        for(auto it: res)
           vis[it]=true;
        
        dfs(0,cnt,adj,vis);
           
       return cnt;     
    }
};