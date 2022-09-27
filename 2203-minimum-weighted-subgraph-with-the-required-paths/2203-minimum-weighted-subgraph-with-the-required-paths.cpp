#define ll long long
class Solution {
public:
    vector<ll> dijkstra(int& src,  vector<vector<pair<int, ll>>>&graph, int &V) {
        vector<ll> distanceToLastNode(V+1, 1e18);
    distanceToLastNode[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>,greater<pair<ll, int>>> pq;
    pq.push({0, src});
      while (!pq.empty()) {
          int u=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            /* TLE Elimination */
            if(distance>distanceToLastNode[u])
                continue;
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
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, ll>>>adj(n+1), rev(n+1);
        for(auto e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            rev[e[1]].push_back({e[0], e[2]});
        }
        
        vector<ll>d1=dijkstra(src1, adj, n);
        vector<ll>d2=dijkstra(src2, adj, n);
        vector<ll>d3=dijkstra(dest, rev, n);
        ll ans=1e18;
        for(int i=0;i<n;i++){
            ans=min(ans, d1[i]+d2[i]+d3[i]);
        }
        if(ans==1e18)return -1;
        return ans;
        
    }
};