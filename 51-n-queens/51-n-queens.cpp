class Solution {
public:
     bool isSafe(int r, int c, vector<string> board, int n){
        if(c==0)
            return true;
        int i= r, j = c;
        while(i>=0  and j>=0){  //check for upper diagonal
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i = r, j= c;
        while(j>=0)  //check for left side
        {
            if(board[i][j]=='Q')
                return false;
            j--;
        }
        i = r, j =c;
        while(i<n and j>=0)  //check for lower diagonal
        {
            if(board[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true; }
    
    
    void f (int i, vector<string> board, vector<vector<string>> &ans, int &n){
        if(i==n){   //if the last queen is placed then, count this in
            ans.push_back(board);
            return;
        }
        for(int r=0; r<n; r++){  //loop used to place the queens in the correct postions one by one in    column wise
            if(isSafe(r, i, board, n)){ //if the position is safe, then place the queen
                board[r][i] = 'Q';  //place the Q
                f(i+1, board, ans, n);
                board[r][i] = '.';  //Check for other possibilities of Q
            }
        }
        return ;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s); //create the board
        f(0, board, ans, n);  //start placing the Q from col=0 and find the correct row for the Q
        return ans; 
    }
};