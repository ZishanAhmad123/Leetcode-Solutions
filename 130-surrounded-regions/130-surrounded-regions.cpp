struct node {
        int x , y;
        node(int X, int Y){
            x=X;
            y=Y;
        }
    };
class Solution {
public:
    void bfs(int a,int b,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        
       // queue<pair<int,int>>q;
        queue<node>q;
        q.push(node(a, b));
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){ 
            
            int x=q.front().x;
            int y=q.front().y;
            q.pop();
            
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m){
                    if(board[new_x][new_y]=='O'){
                        board[new_x][new_y]='Z';
                         q.push(node(new_x, new_y));
                    }
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ // an 'O' should not be flipped if: // - It is on the border, or // - It is adjacent to an 'O' that should not be flipped.
                
                //check 'O' in the border region and convert its connected regions to 'Z'
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j]=='O'){
                        board[i][j]='Z';
                        bfs(i,j,board);
                    }
                }
            }
        }
        // convert all 'Z' to 'O' and others to 'X'
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Z')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};