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
        // I_NEED_CAMERA -1
        // I_AM_COVERED 1
        // I_HAVE_CAMERA 0
    
     int camera = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 1;
        int left = dfs(root->left);              // take information from left child
        int right = dfs(root->right);             // take information from right child
        
        if(left == -1 || right == -1){
            camera++;
            return 0;
        }
    
        if(left == 0 || right == 0) return 1;

        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        int rootSays = dfs(root);
        if(rootSays == -1) camera++;
        return camera;
    }
};