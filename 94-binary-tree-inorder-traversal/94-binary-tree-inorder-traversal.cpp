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
   void inorder(TreeNode* node, vector<int> &ans){
            if(node == NULL)  //base case
                return;
            inorder(node->left, ans); //goes to the left node
            ans.push_back(node->val); //store the root node value
            inorder(node->right, ans); // finally go to the right node
        }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans; //declare a vector to store result
        inorder(root, ans);
        return ans;
    }
};