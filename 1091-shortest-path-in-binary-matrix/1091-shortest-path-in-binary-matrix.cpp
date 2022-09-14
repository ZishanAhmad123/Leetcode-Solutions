class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         if(grid[0][0]==1)return -1;  // not possible
        int m=grid.size(),n=grid[0].size();
        queue<vector<int>>q;
        q.push({0,0,1});  // i,j,distance
        int dir[8][2]={{0,-1},{0,1},{-1,0},{1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            int si=q.size();
            for(int i=0;i<si;i++){
                auto top=q.front();
                q.pop();
                if(top[0]==m-1 and top[1]==n-1)return top[2];
                for(auto it : dir){
                    int r = top[0]+it[0];
                    int c = top[1]+it[1];
                    if(r>=0 and c>=0 and r<m and c<n and grid[r][c]==0){
                        q.push({r,c,top[2]+1});  // if new position grid[r][c]==0 we found just steps+1
                        grid[r][c]=1;
                    }
                }
            }
        }
        return -1;
    }
};