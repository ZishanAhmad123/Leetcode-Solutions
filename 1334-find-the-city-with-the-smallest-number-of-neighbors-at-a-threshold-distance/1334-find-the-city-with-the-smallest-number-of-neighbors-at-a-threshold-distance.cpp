class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // more explanation on Alisha video
//            unordered_map<int,vector<pair<int,int>>> adj;
//         for(auto e: edges)
//         {
//             adj[e[0]].push_back({e[1],e[2]});
//             adj[e[1]].push_back({e[0],e[2]});
//         }
//         //for all the nodes we can find the shortest paths to all other nodes.
//         //then we can calculate the number of cities within the threshold k
//         //we will store that info in reachables array
//         vector<int> reachables(n);
//         for(int i=0;i<n;i++)
//         {
//             vector<int> dist(n,1e7);
//             queue<int> q;
//             q.push(i);
//             dist[i]=0;
//             while(!q.empty())
//             {
                
//                 int curr = q.front();
//                 q.pop();
//                 for(auto [next,edge] : adj[curr])
//                 {
//                     if(dist[curr]+edge<dist[next])
//                     {//update distance if we find a shorter path.
//                         dist[next] = dist[curr]+edge;
//                         q.push(next);
//                     }
//                 }
//             }
            
            
//             int count=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(dist[j] && dist[j]<=k)
//                     count++;
//             }
//             reachables[i] = count;
//         }
//           //using reachables, find the city with minimum neighbours within k distance
//         int resCount = INT_MAX,res;
//         for(int i=0;i<n;i++)
//         {
//             if(reachables[i]<=resCount)
//             {
//                 resCount = reachables[i];
//                 res = i;
//             }
//         }
//         return res;

        // Floyd Warshall
          vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
            dist[i][i]=0;
        for(vector<int>v:edges)          // given filling 
        {
            dist[v[0]][v[1]] = v[2];
             dist[v[1]][v[0]] = v[2];
        }
        
        // Now Updating 
        for(int k=0;k<n;k++) //pivot
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX &&dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j]= dist[i][k]+dist[k][j];
                }
            }
        }
         
        int citycount;
        int ans;
        for(int i=0;i<n;i++)
        {    int count = 0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dist[i][j]<= distanceThreshold)
                    count++;
            }
             
         if(count<=citycount)
         { 
             ans = i;
             citycount = count;
             
         }
        }
        return ans;
        
        
    }
};