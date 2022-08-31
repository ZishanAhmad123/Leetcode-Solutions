typedef pair<int,int> pp;
class Solution {
public:
    int m,n;
    void util(vector<vector<int>>& heights, int i, int j, set<pp>& st, int prevH)
    {
		//out of bounds check
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
		//if cell has already been explored
		if(st.find({i,j}) != st.end())
            return;
		//if height condition does not satisfy
        if(heights[i][j] < prevH)
            return;
        st.insert({i,j});
        util(heights,i-1,j,st,heights[i][j]); //explore left
        util(heights,i+1,j,st,heights[i][j]); //explore right
        util(heights,i,j-1,st,heights[i][j]); //explore up
        util(heights,i,j+1,st,heights[i][j]); //explore down
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pp> alt;
        set<pp> pac;
        m = heights.size();
        n = heights[0].size();
        for(int i = 0; i < m; i++)
        {
            util(heights,i,n-1,alt,heights[i][n-1]);
            util(heights,i,0,pac,heights[i][0]);
        }
        for(int i = 0; i < n; i++)
        {
            util(heights,m-1,i,alt,heights[m-1][i]);
            util(heights,0,i,pac,heights[0][i]);
        }
        vector<vector<int>> res;
        for(auto it : alt)
        {
            if(pac.find(it) != pac.end()) //get intersection of both the sets
                res.push_back({it.first,it.second});
        }
        return res;
    }
};