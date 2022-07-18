class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
         int m = matrix.size();
        int n = matrix[0].size();
        
        // Prefix sum of each row
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        // Subarray to target sum with adjustment of the column c1 & c2
        int count = 0;
        for (int c1 = 0;  c1 < n; c1++) {
            for (int c2 = c1; c2 < n; c2++) {
                unordered_map<int, int> mymap;
                int val = 0;
                for (int r = 0; r < m; r++) {
                    val += matrix[r][c2] - ((c1 == 0) ? 0 : matrix[r][c1-1]);
                    if (val == target) {
                        count++;
                    }
                    if (mymap.find(val - target) != mymap.end()) {
                        count += mymap[val - target];
                    }
                    mymap[val]++;
                }
            }
        }
        
        return count;
    }
};