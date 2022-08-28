class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> lines;
        
        for (int i = mat.size() - 1; i >= 0; i--)
        {
            int r = i;
            int c = 0;
            
            lines.push_back(std::vector<int>());
            while (r < mat.size() && c < mat[0].size())
            {
                lines.back().push_back(mat[r][c]);
                r++;
                c++;
            }
            
            sort(lines.back().begin(), lines.back().end());
        }
        
        for (int i = 1; i < mat[0].size(); i++)
        {
            int r = 0;
            int c = i;
            
            lines.push_back(vector<int>());
            while (r < mat.size() && c < mat[0].size())
            {
                lines.back().push_back(mat[r][c]);
                r++;
                c++;
            }
            
            sort(lines.back().begin(), lines.back().end());
        }
        
        int iLine = 0;
        for (int i = mat.size() - 1; i >= 0; i--)
        {
            int r = i;
            int c = 0;
            
            int jLine = 0;
            while (r < mat.size() && c < mat[0].size())
            {
                mat[r][c] = lines[iLine][jLine];
                jLine++;
                r++;
                c++;
            }
            
            iLine++;
        }
        
        for (int i = 1; i < mat[0].size(); i++)
        {
            int r = 0;
            int c = i;
            
            int jLine = 0;
            while (r < mat.size() && c < mat[0].size())
            {
                mat[r][c] = lines[iLine][jLine];
                jLine++;
                r++;
                c++;
            }
            
            iLine++;
        }
        
        return mat;
    }
};