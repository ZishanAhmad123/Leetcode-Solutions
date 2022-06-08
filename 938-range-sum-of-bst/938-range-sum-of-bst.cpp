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
    void inorder(TreeNode* root, vector<int>&v)
    {
       if(root!=NULL)
       {
           inorder(root->left,v);
           v.push_back(root->val);
           inorder(root->right,v);
       }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>v;
        inorder(root, v);
        int sum=0;
        for(auto x: v){
            if(x<=high && x>=low){
                sum+=x;
            }
        }
        return sum;
    }
};