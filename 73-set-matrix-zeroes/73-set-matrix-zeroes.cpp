class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int nr, nc;
    vector<vector<int>> copy;
    nr=matrix.size();
    nc=matrix[0].size();
    set<int> rows;
    set<int> cols;
    
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    for(auto r : rows){
        for(int j=0;j<nc;j++){
            matrix[r][j]=0;
        }
    }
    
    for(auto c : cols){
        for(int i=0;i<nr;i++){
            matrix[i][c]=0;
        }
    } 
    }
};