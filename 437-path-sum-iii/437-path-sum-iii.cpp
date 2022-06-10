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
public:  unsigned int count=0;
    int mod = 1e9+7;
    vector<int>v;
    void getsum(TreeNode* root, int targetSum){
        if(root==NULL)return;
        
        v.push_back(root->val);
        getsum(root->left,targetSum);
        getsum(root->right, targetSum);
        
       unsigned int  temp=0;
        for(int i=v.size()-1; i>=0; i--){
            temp+=v[i];
            if(temp==targetSum)count++;
        }
       v.pop_back();
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
         getsum(root, targetSum);
        return count;
    }
};