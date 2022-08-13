   struct node {
        int x , y, time=0;
        node(int X, int Y, int Time){
            x=X;
            y=Y;
            time=Time;
        }
    };
class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
       queue<node>q;
       vector<vector<int>>visit(n, vector<int>(m ,0));
        int cntOrange=0;
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push(node(i, j, 0));       // multivalued bfs
                    visit[i][j]=1;
                }
                else visit[i][j]=0;
                if(grid[i][j]==1)cntOrange++;
            }
        }
        int ans=0;
        int cnt=0;
        int dx[4]={-1, 0, +1, 0};
        int dy[4]={0, 1, 0, -1};
        
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int time=q.front().time;
            q.pop();
            
            ans=max(ans, time);
    
            for(int ind=0; ind<4; ind++){
                int newx=x+ dx[ind];
                int newy=y+ dy[ind];
               if(newx>=0 && newx<n  && newy>=0 && newy<m && grid[newx][newy]==1 && visit[newx][newy]==0){
                   visit[newx][newy]=1;
                   q.push(node(newx, newy, time+1));cnt++;
                }
            } 
        }
       // cout<<cnt;
        if(cnt!=cntOrange)return -1;
        return ans;
    }
};