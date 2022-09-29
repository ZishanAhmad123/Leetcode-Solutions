class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
         int n = quiet.size(); 
    vector<int> indegree(n,0);
    vector<int> ans(n,0);
    vector<vector<int>> adj(n);
    queue<int> q;
    
    for(auto it: richer)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    
    for(int i =0;i<n;i++)
    {
        ans[i]=i;
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
            if(quiet[ans[it]]>quiet[ans[node]])
            {
                ans[it]= ans[node];
            }
                
            indegree[it]--;
            
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
    }
};