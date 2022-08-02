class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();   vector<int>v;
       
        for(int i=0;i<n*m; i++)
            v.push_back(matrix[i/m][i%m]);
        
        sort(begin(v), end(v));
        return v[k-1]; 
    }
};