class Solution {
public:
 static const int N=1e6;
int parent[N];
int Size[N];
void make(int v){parent[v]=v;Size[v]=1;}
int find(int v){if(v==parent[v]) return v;return parent[v]=find(parent[v]);}
void Union(int a, int b){a= find(a);b=find(b);if(a!=b){if(Size[a]>Size[b])swap(a, b);parent[b]=a;	Size[a]+=Size[b];}}
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;

        for(int i=0;i<n;i++)
            make(i);
        
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0], v=connections[i][1];
            
            u=find(u);
            v=find(v);
            
            if(u!=v)                 // no cylce
                Union(u,v);
        }
    
    int  cnt=0;
        for(int i=0;i<n;i++){          // connected Component
            if(find(i)==i)
            cnt++;
        }
        return cnt-1;
    }
};