class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<vector<int>>& land, int i, int j){
        if(i < 0 or i >= land.size() or j < 0 or j >= land[0].size() or land[i][j] == 0 or land[i][j] == 2) return;
    
        land[i][j] = 2;      //mark as visited
		
		// if land[i][j] is the top left starting point of the farmland.
        if((i - 1 < 0 or land[i-1][j] == 0) and (j - 1 < 0 or land[i][j-1] == 0)) res.push_back({i, j}); 
		// if land[i][j] is the bottom right ending point of the farmland.
        if((i + 1 == land.size() or land[i+1][j] == 0) and (j + 1 == land[0].size() or land[i][j+1] == 0)) {
            res.back().push_back(i);
            res.back().push_back(j);
        }
        dfs(land, i+1, j); 
        dfs(land, i, j+1);
		
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j] == 1)
                dfs(land, i, j);
            }
        }
        return res;
    }
};