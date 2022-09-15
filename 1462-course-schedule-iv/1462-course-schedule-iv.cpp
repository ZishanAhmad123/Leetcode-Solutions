class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& qr) {
          vector<int> indegree(n , 0) , adj[n];
        for(int i=0 ; i<p.size() ; i++) {
            int u = p[i][0];
            int v = p[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i=0 ; i<n ; i++) {
            if(!indegree[i]) q.push(i);
        }
        vector<vector<bool>> isReachable(n , vector<bool>(n , false));
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                indegree[v]--;
                isReachable[u][v] = true;
                for(int i=0 ; i<n ; i++) {
                    if(isReachable[i][u]) isReachable[i][v] = true;
                }
                if(!indegree[v]) {
                    q.push(v);
                }
            }
        }
        vector<bool> ans((int)qr.size() , false);
        for(int i=0 ; i<qr.size() ; i++) {
            if(isReachable[qr[i][0]][qr[i][1]]) {
                ans[i] = true;
            }
        }
        return ans;
    }
};