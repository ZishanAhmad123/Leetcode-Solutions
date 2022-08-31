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
     unordered_map<long , long> mp;
    long maxi_in_map = 1;
    int recur(TreeNode* root){
        if(!root) return 0;
        int s = recur(root->left) + recur(root->right) + root->val;
        maxi_in_map = max(maxi_in_map, ++mp[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        recur(root);
        vector<int> res;
        for(auto it: mp){
            if(it.second == maxi_in_map){
                res.push_back(it.first);
            }
           // cout<<it.first<<"-> "<<it.second<<endl;
        }
        return res;
    }
};