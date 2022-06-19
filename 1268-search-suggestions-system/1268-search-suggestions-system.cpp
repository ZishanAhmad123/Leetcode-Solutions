class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         sort(products.begin(), products.end());
        int n = searchWord.size();
        vector<vector<string>> res(n);
        for(int i=0; i<products.size(); i++){
            for(int j=0; j< products[i].size() && j<n; j++){
                if(products[i][j]==searchWord[j]){
                    if(res[j].size()<3)res[j].push_back(products[i]);
                }
                else break;
            }
        }
        return res;
    }
};