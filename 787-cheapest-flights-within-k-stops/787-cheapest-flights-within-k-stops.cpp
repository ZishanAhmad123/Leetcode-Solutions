class Solution {
    public:
    int bfs(int n, vector<pair<int,int>> adjList [],int src,int dst,int k){
        vector<int>distance(n,INT_MAX);
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,src},0}); // 1 is distance // 2nd is node // 3rd is count
        distance[src]=0;
        while (!q.empty()){
            int initialPrice=q.front().first.first;
            int node=q.front().first.second;
            int count=q.front().second;
            q.pop();
            for (auto &it:adjList[node]){
                int nodal=it.first;
                int price=it.second;
                if (price+initialPrice<distance[nodal] && count<=k){
                    distance[nodal]=price+initialPrice;
                    q.push({{price+initialPrice,nodal},count+1});
                }
            }
            
        }
        return distance[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int> > adjList[n];
        int row=flights.size();
        int col=flights[0].size();
        for (int i=0;i<row;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adjList[u].push_back({v,w});
                
        }
        int ans=bfs(n,adjList,src,dst,k);
        
        if (ans==INT_MAX)
            return -1;
        return ans;
        
    }
};