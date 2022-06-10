class Solution {
public:
   static const int N=1e6;
    int parent[N];
int Size[N];
void make(int v){parent[v]=v;Size[v]=1;}
int find(int v){if(v==parent[v]) return v;return parent[v]=find(parent[v]);}
void Union(int a, int b){a= find(a);b=find(b);if(a!=b){if(Size[a]>Size[b])
    swap(a, b);parent[b]=a;	Size[a]+=Size[b];}}
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
         vector<int>ans;
     for(int i=1; i<=n; i++){
         make(i);
     }
        for(auto edge: edges){
            int u= edge[0];int v=edge[1];
            
            if(find(u)==find(v)){
           ans.push_back(u);
             ans.push_back(v);}
            Union(u, v);
        }
        
        return ans;
    }
};