class Solution {
public:
     int INF=1e8;
    
    void bfs( int node1, vector<vector<int>>&adj,vector<int>&dist1  ){
        queue<int>q;
        q.push(node1);
       dist1[node1]=0;
        while(!q.empty()){                        // distance of all node from node1 and node2
            for(int i=0;i<size(q);i++){
                auto node=q.front();
                q.pop();
                for(auto child:adj[node]){
                    if(dist1[child]==INF){
                        dist1[child]=dist1[node]+1;
                        q.push(child);
                    }
                }
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int n=edges.size();
         vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
    //call bfs
    vector<int>dist1(n,INF),dist2(n,INF);
    bfs(node1,adj,dist1);
    bfs(node2,adj,dist2);
        
        int maxi=1e9;
        int index=-1;
        for(int i=0;i<n;i++){                     // finding maximum distance index
            if(dist1[i]!=INF&&dist2[i]!=INF){
              int max_d=max(dist1[i],dist2[i]);
                if(maxi>max_d){
                    maxi=max_d;
                    index=i;
                }
            }
        }
        return index;
        
        
    }
};