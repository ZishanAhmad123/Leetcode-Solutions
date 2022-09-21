class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() , cnt = 0;
    queue<pair<int , int>>q;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1){    // saare boundry 1 se connected 1 ko 0 set kr do bs aur last remaning 1 cnt krlo
                grid[i][j] = 0;
                q.push({i , j});
            }
    while(q.size()){
        int x = q.front().first , y = q.front().second;
        q.pop();
           int dx[]={-1,0,1,0};
           int dy[]={0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int r = x + dx[i] , c = y + dy[i];
            if(r >= 0 && r < m && c >=0 && c < n && grid[r][c] == 1){
                grid[r][c] = 0;
                q.push({r , c});
            }
        } 
    }            
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)   
            if(grid[i][j] == 1)
             cnt++;
    return cnt;
    }
};