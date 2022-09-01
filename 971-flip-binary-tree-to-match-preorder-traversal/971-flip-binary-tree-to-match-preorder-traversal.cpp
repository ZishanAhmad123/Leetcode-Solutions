/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i=0;
    vector<int>res;
    bool dfs(TreeNode* root, vector<int>& voyage){
        if(root==NULL) return true;
        if(root->val !=voyage[i++]) return false;
        if(root->left !=NULL && root->left->val !=voyage[i]){
            res.push_back(root->val);
            return dfs(root->right,voyage) && dfs(root->left,voyage);
        }
        else return dfs(root->left,voyage) && dfs(root->right,voyage); 
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(!dfs(root,voyage)) 
            res = {-1};
        return res;
    }
};