class TreeAncestor {
public:
     vector<vector<int>> table;
    TreeAncestor(int n, vector<int>& par) {
       table.resize(16,vector<int>(n,0));
        for(int i=0;i<n;i++){
            table[0][i] = par[i];
        }
        //table[i][j]  =>  i=0 -> first parent  i=1 -> 2nd parent  i=2 ->4th parent
        for(int i=1;i<16;i++){
            for(int j=0;j<n;j++){
                if(table[i-1][j]==-1) table[i][j]=-1;
                else
                table[i][j] = table[i-1][table[i-1][j]];
            }
        }
    }

    int getKthAncestor(int node, int k) {
      for(int i=0;i<16;i++){
          int mask = (1<<i);
          if(k&mask){
              node = table[i][node];
              if(node==-1) return -1;
          }
      }
      return node;
    }
};
