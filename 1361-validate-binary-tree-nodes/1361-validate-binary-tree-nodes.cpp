class Solution {
public:
     // topological sort
    vector<int> topoSort(int V, vector<vector<int>>&adj) {
    vector <int> indegree(V, 0);
     vector <int> topo;
	    for(int i=0; i<V; i++){
	        for(auto j:adj[i])
	            indegree[j]++;
	    } queue <int> q;
	    for(int i=0; i<V; i++){
             if(indegree[i]>1)return { } ;
	        if(indegree[i] == 0)  q.push(i); }
	    int cnt=0;
	    while(!q.empty()){
	        int t = q.front();  q.pop(); cnt++;
	        topo.push_back(t);
	        for(auto i:adj[t]){
	            indegree[i]--;
	            if(indegree[i] == 0)q.push(i);}  }
	   if(cnt==V)return topo;                  
         else return {};}
    
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
      
        vector<vector<int>>mat(n) ;        // making  possible graph 
        int edges = 0 ;
        vector<int>indeg(n,0) ;
        
        for(int i=0;i<n;i++)
        {
            if(left[i]!=-1)
            {
                mat[i].push_back(left[i]) ;
                edges++ ;
            }
        }
        for(int i=0;i<n;i++)
        {
            if( right[i] != -1 )
            {
                mat[i].push_back(right[i]) ;
                edges++ ;
            }
        }
        
      vector<int> topo=topoSort(n, mat);        //if graph have no toposort means no cylce yani that graph is tree                                                                 count(edges) should be n-1 for tree
        if(topo.size()!=n || edges!=n-1)return false;
        return true;
        }
};