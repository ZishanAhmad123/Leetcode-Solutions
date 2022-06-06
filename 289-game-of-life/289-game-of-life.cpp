class Solution {
public:
    int noOfOnes(int i, int j ,vector<vector<int>>& board, int m, int n ){
        int cnt =0;
         
                if(i>0 && board[i-1][j]>=1) cnt++;
                if(i<n-1 && board[i+1][j]>=1) cnt++; 
                if(j>0 && board[i][j-1]>=1) cnt++; 
                if(j<m-1 && board[i][j+1]>=1) cnt++;
                
                if(i>0 && j>0 && board[i-1][j-1]>=1) cnt++; 
                if(i>0 && j<m-1 && board[i-1][j+1]>=1) cnt++; 
                if(i<n-1 && j>0 && board[i+1][j-1]>=1) cnt++; 
                if(i<n-1 && j<m-1 && board[i+1][j+1]>=1) cnt++; 
        
        return cnt;
    } 
    
    void gameOfLife(vector<vector<int>>& board) {
         int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                
                // live cases
                  if(board[i][j]==1 && (noOfOnes(i,j,board,m,n)<2 || noOfOnes(i,j,board,m,n)>3)) 
                    board[i][j]=2;
                
                if(board[i][j]==0 &&noOfOnes(i,j,board,m,n)==3) 
                    board[i][j]=-1;
            }
        
        // die cases
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(board[i][j]==2) 
                    board[i][j]=0;
                if(board[i][j]==-1) 
                    board[i][j]=1;
            }
            
        return;
    }
};