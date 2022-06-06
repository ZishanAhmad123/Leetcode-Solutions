class Solution {
public:
int n;
int m;
bool visited[7][7];
vector<vector<char>> board;
string word;
    bool solve(int i , int j , int ind)
{

    if(ind==word.size())
        return true;
    if(i<0 or j<0 or i>=n or j>=m)
        return false;
    if(visited[i][j])
        return false;
    if(board[i][j]!=word[ind])
        return false;
    
    visited[i][j]=true;
    if(solve(i+1 , j , ind+1))
        return true;
    if(solve(i , j+1 , ind+1))
        return true;
    if(solve(i-1 , j , ind+1))
        return true;
    if(solve(i , j-1 , ind+1))
        return true;
    visited[i][j]=false;
    
    return false;
    
}
bool exist(vector<vector<char>>& board1, string word1) {
    
    n=board1.size();
    m=board1[0].size();
    board=board1;
    word=word1;
    
   for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
           if(solve(i, j,0) )
               return true;
    
  return false;
    
    
}
};