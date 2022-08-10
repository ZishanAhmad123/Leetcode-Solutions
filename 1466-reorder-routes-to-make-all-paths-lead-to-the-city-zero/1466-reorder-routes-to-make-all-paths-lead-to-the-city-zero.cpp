class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
       vector<int> adj[n];
        vector<int> back_adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            back_adj[v].push_back(u);
        }
        
        queue< int> q;
        q.push(0);
        
        vector<bool> visited(n , false);
        visited[0]=true;
        int cnt=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            // traverse all the nodes which are going away
            // from 0 
            
            for(auto x : adj[node])
            {
                if(visited[x]==false)
                {
                    q.push(x);
                    visited[x]=true;
                    cnt++;
                }
            }
            
            // Now which are not reachable , reached to it 
            // means they are in directional edges , means towards 0
            // but we have to visit it , as it may occurs some edges
            // which are away from 0 , so for that we have to visit 
            
            // all the nodes
            
            for(auto x : back_adj[node])
            {
                if(visited[x]==false)
                {
                    q.push(x);
                    visited[x]=true;
                    
                }
            }
        }
        
        return cnt; 
    }
};