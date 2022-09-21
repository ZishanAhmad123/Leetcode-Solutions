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
    TreeNode* lca(TreeNode* root,int a,int b){
        if(root==NULL) return NULL;
        if(root->val==a || root->val==b){
            return root;
        }
        TreeNode* l = lca(root->left,a,b);
        TreeNode* r = lca(root->right,a,b);
        if(l and r) return root;
        
        return l?l:r;
    }
     TreeNode* solve(TreeNode*root,int node,string& ans)
    {
        if(root==NULL)
            return NULL;
        if(root->val==node)
            return root;
    
        TreeNode*left=solve(root->left,node,ans);
        TreeNode*right=solve(root->right,node,ans);
        if(left==NULL and right==NULL)
            return NULL;
        else if(right)
        {
            ans+='R';
            return right;
        }
        else if(left)
        {
            ans+='L';
            return left;
        }
        else 
            return root;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *LCA= lca(root,startValue,destValue);
        string a = "",b = "";
        solve(LCA,destValue,b);
        solve(LCA,startValue,a);
        string str(a.size(), 'U');
    
        reverse(b.begin(), b.end());
        return str+b;
    }
};