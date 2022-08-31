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
        vector<TreeNode*> ans;
        map<string,int> mp;
    
string findSubtreesNodes(TreeNode* root){
    if(root==NULL) return "#";
    
    string ls = findSubtreesNodes(root->left);
    string rs = findSubtreesNodes(root->right);
    
    string s = to_string(root->val)+"$"+ls+"$"+rs;
    if(mp[s]==1) ans.push_back(root);
    mp[s]++;
    
    return s;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
   findSubtreesNodes(root);
   
    for(auto it: mp){
            cout<<it.first<<"-> "<<it.second<<endl;
        }
     return ans;
  }   
};