class Solution {
public:
    // this question is of TREE REEROOTING CONCEPT
    vector<int> subtree;
    vector<int> ans;
    vector<int> num;
    vector<vector<int>> adj;
    int n;
    
    void dfs1(int node, int par){
        num[node] = 1;
        for(auto x : adj[node]){
            if(x == par) continue;
            dfs1(x, node);
            num[node] += num[x];
            subtree[node] += subtree[x] + num[x];
        }
    }
    
    void dfs2(int node, int par){
        for(auto x : adj[node]){
            if(x == par) continue;
            ans[x] = subtree[x] + (ans[node] - (subtree[x] + num[x])) + (n - num[x]);
            dfs2(x, node);
        }
    }
    
    vector<int> sumOfDistancesInTree(int nn, vector<vector<int>>& edges) {
        n = nn;
        subtree.resize(n);
        ans.resize(n);
        adj.resize(n);
        num.resize(n, 0);
        for(int i = 0; i < n - 1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(0,-1);
        ans[0] = subtree[0];
        dfs2(0,-1);
        return ans;
    }
    
};