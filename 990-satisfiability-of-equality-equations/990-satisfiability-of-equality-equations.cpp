class Solution {
public:
 static const int N=1e6;
 
int parent[N];
int Size[N];
void make(int v){parent[v]=v;Size[v]=1;}
int find(int v){if(v==parent[v]) return v;return parent[v]=find(parent[v]);}
void Union(int a, int b){a= find(a);b=find(b);if(a!=b){if(Size[a]>Size[b])swap(a, b);parent[b]=a;	Size[a]+=Size[b];}}
                                                       
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0; i<26 ;i++){
            make(i);
        }
        
        for(auto e: equations){
            if(e[1]=='='){
                Union(e[0]-'a', e[3]-'a');
            }
        }
        
        for(auto e: equations){
            if(e[1]=='!'){
                int p1=find(e[0]-'a');
                int p2=find(e[3]-'a');
                if(p1==p2)return false;
            }
        }
    return true ;
    }
};