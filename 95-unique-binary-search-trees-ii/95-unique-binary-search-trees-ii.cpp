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
            vector<TreeNode*> f (int l ,int r){
                if(l>r)return {NULL};
                vector<TreeNode* >ans;
                for(int root=l; root<=r; root++){
                    
                    vector<TreeNode* >left=f (l, root-1);
                    vector<TreeNode* >right=f(root+1, r);
                    
                     for(auto Node_l:left ){
                         for(auto Node_r: right){
                              TreeNode* node= new TreeNode(root);
                             node->left=Node_l;
                             node->right=Node_r;
                             ans.push_back(node);
                         }
                     }
                }
                return ans;
            }
    
    vector<TreeNode*> generateTrees(int n) {
       return f(1, n);
    }
};