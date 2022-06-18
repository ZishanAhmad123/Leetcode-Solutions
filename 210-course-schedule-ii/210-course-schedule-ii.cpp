class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
          vector <vector<int>> adj(n);        //to store neighbors of each node
        vector <int> in(n, 0);              //to store degrees of each node
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0; i<n; i++){              // indegree of each node
            for(auto child : adj[i])
                in[child]++;
        }   
        queue <int> q;                      //to store the nodes which needs to be excluded in order to reach the middle nodes
        for(int i=0; i<n; i++)
            if(in[i]==0)
                q.push(i);
        int cnt=0;
        vector <int> res;                   //to store the final result
        while(!q.empty())
        {
            int size=q.size();
            while(size--)           //doing for each inserted nodes
            {
                int cur=q.front();
                q.pop();
                cnt++;
                res.push_back(cur); //adding nodes to vector (it may or may not be the final solution)
                for(auto &neigh :adj[cur])
                {
                    in[neigh]--;            //removing current leave nodes
                    if(in[neigh]==0)        //adding current leave nodes
                        q.push(neigh);
                }
            }
        }
       if(cnt==n)return res;                   // topological sort
         else return {};
    }
};