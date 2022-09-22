class Solution {
public:
    struct DSU {
        vector<int> sz;       // by size
        vector<int> parent;
        DSU(int n) {
            sz.resize(n+1 , 0);
            parent.resize(n+1 , 0);
            for(int i=1 ; i<=n ; i++) parent[i] = i;
            for(int i=1 ; i<=n ; i++) sz[i] = 1;
        }
        int find(int u) {
            if(parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }
        bool merge(int u , int v) {
            u = find(u);
            v = find(v);
            if(u == v) return false;
            if(sz[u] > sz[v]) {
                parent[v] = u;
                sz[u] += sz[v];
            } else {
                parent[u] = v;
                sz[v] += sz[u];
            }
            return true;
        }
        int size(int x) {
            return sz[x];
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& g) {
        vector<pair<int , int>> alice;
        vector<pair<int , int>> bob;
        vector<pair<int , int>> both;
        for(int i=0 ; i<g.size() ; i++) {
            int t = g[i][0];
            int u = g[i][1];
            int v = g[i][2];
            if(t == 1) {
                alice.push_back({u , v});
            } else if(t == 2) {
                bob.push_back({u , v});
            } else {
                both.push_back({u , v});
            }
        }
        DSU a(n) , b(n);
        int used = 0;
        for(int i=0 ; i<both.size() ; i++) {
            int u = both[i].first;
            int v = both[i].second;
            used += a.merge(u , v);
            b.merge(u , v);
        }
        for(int i=0 ; i<alice.size() ; i++) {
            int u = alice[i].first;
            int v = alice[i].second;
            used += a.merge(u , v);
        }
        for(int i=0 ; i<bob.size() ; i++) {
            int u = bob[i].first;
            int v = bob[i].second;
            used += b.merge(u , v);
        }
        if(a.size(a.find(1)) < n || b.size(b.find(1)) < n) return -1;
        return (int)g.size() - used;
    }
};