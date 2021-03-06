class Solution {
public:
  static const int N=1e6;  
 int parent[N];
 int Size[N];
void make(int v){parent[v]=v;Size[v]=1;}
int find(int v){if(v==parent[v]) return v;return parent[v]=find(parent[v]);}
void Union(int a, int b){a= find(a);b=find(b);if(a!=b){if(Size[a]>Size[b])swap(a, b);parent[b]=a;	Size[a]+=Size[b];}}
    
   int minCostConnectPoints(vector<vector<int>>& points) {
       vector<pair<int , pair<int, int>>>edges;
       
       for(int i=0; i<size(points); i++){             // all possibilities of coordinates;
       for(int j=i+1; j<size(points); j++){
               int valX=abs(points[i][0]-points[j][0]);
                int valY=abs(points[i][1]-points[j][1]);
                int dist=valX+valY;
           edges.push_back({dist, {i, j}});
           }
       }
       
       sort(edges.begin(), edges.end());         // sort A/c to weight
       for(int i=1; i<=size(points); i++){       // make nodes
           make(i);
       }
       int total_cost=0;
       for(auto edge : edges){
           int wt=edge.first;
           int u=edge.second.first;
           int v=edge.second.second;
           
           if(find(u)==find(v))continue;
           
           Union(u, v);
           total_cost+=wt;
       }
       return total_cost; 
    }
};