class Solution {
public:
     map<pair<int,int>,pair<int,int>>parent;
    const int dx[4] = {-1,0,1,0} ;
    const int dy[4] = {0,1,0,-1} ;
    int r , c ;
    vector<vector<int>> visited ;
    
    bool isValid(int i , int j){
        return i >= 0 and j >= 0  and i < r and j < c ;
    }
    bool dfs(int i , int j , int pi , int pj , vector<vector<char>> &grid ){
        if(visited[i][j])
            return true ;
        visited[i][j] = 1 ;
        
          for(int dir = 0 ; dir < 4 ; ++dir){
            int ii = i + dx[dir] , jj = j + dy[dir] ;
            if(isValid(ii,jj) and (ii != pi || jj != pj) and grid[i][j] == grid[ii][jj]){
                if(dfs(ii,jj,i,j,grid)) return true ;
            }
        }
        return false ;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        r = grid.size() , c = grid[0].size() ;
        visited.resize(r,vector<int>(c));
        
        
        for(int i = 0 ; i < r ; ++i ){
            for(int j = 0 ; j < c ; ++j ){
                if(!visited[i][j] and dfs(i,j,-1,-1,grid)) return true ;
            }
        }
        return false ;
    }
};