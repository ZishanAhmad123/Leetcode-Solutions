class DSU
    {
        public:
        vector<int>par,size;
        DSU(int n)
        {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        
        int find(int x)
        {
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }
        
        bool Union(int a,int b)
        {
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)return 1;
            
            if(size[pa]>size[pb])
            {
                par[pb]=pa;
                size[pa]+=size[pb];
            }
            else
            {
                par[pa]=pb;
                size[pb]+=size[pa];
            }
            return 0;
        }
    };

class Solution {
public:
     bool matching(const string a, const string b){
        int n = a.size();
        int count = 0;
        for(int i=0;i<n;i++){
            count += (a[i] != b[i]);
        }
        return count == 0 || count == 2;
    }
    
    int numSimilarGroups(vector<string>& strs) {
         int n = strs.size();
          DSU dsu(n);
        
        for(int i=0; i<n; ++i) {          // each pair check for matching condition
            for(int j=i+1; j<n; ++j) {
                if(matching(strs[i], strs[j])) {
                    dsu.Union(i, j);
                }
            }
        }
        
        unordered_set<int> st;
        for(int i=0; i<n; ++i) {      // find component
            st.insert(dsu.find(i));
        }
        return st.size();
    }
};