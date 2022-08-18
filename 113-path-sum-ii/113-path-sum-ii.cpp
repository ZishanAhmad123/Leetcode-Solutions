class Solution {
public:
    void dfs(TreeNode* root, int Tsum,vector<int>& path,vector<vector<int>> &ans, int sum){
         if(!root) return ;
         path.push_back(root->val);
         sum+=root->val;
         if(!root->left and !root->right and Tsum==sum) {
             ans.push_back(path);
         }
         else{
         dfs(root->left, Tsum, path, ans, sum);        //Traverse on left 
         dfs(root->right, Tsum, path, ans, sum);  
         }  
         path.pop_back();                // pop out last entering element
     }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum=0;
        dfs(root, targetSum, path, ans, sum);
        return ans;
    }
};