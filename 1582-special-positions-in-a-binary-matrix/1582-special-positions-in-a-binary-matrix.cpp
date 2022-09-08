class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
     int res=0;
        vector<int> row(mat.size(),0);// sum of row
        vector<int> col(mat[0].size(),0);// sum of col 
        
        for(int i=0;i<mat.size();i++)
        {
            int t=0;
            for(int j=0;j<mat[0].size();j++)
                t+=mat[i][j];
            row[i]=t;
        }
        for(int j=0;j<mat[0].size();j++)
        {
            int t=0;
            for(int i=0;i<mat.size();i++)
                t+=mat[i][j];
            col[j]=t;
        }
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
            // row and col ==1 means mat[i][j]==1 was only the element in the row and col ( special )
                if(mat[i][j]==1 && row[i]==1 && col[j]==1)
                    res++;
            }
        }
        return res;
}
};