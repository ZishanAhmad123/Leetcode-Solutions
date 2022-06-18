class Solution {
public:
void dfs(vector<vector<int>>& graph , vector<int> &visit , int node , vector<vector<int>>& ans , vector<int> &v){
    int n = graph.size();
    
    if(node == n-1){  
        ans.push_back(v);
        return;
    }
    visit[node] = 1;  
    
    for(auto child:graph[node]){
        if(!visit[child]){
         v.push_back(child);  
            dfs(graph , visit , child , ans , v);  
        }
        v.pop_back();     //backtracking
    }
    visit[node] = 0;  
    return;
}  
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visit(n , 0);
    vector<vector<int>> ans;
    vector<int> v;
    
     v.push_back(0);   
    dfs(graph , visit , 0 , ans , v);
    return ans;
    }
};