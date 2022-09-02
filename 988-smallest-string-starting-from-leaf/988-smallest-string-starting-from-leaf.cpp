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
    priority_queue<string,vector<string>,greater<string>>pq;
    
    void dfs(TreeNode* root,string str){        // traverse and calculate every string from root to leaf
        if(!root)
            return;
        str+=root->val+'a';
        if(!root->left and !root->right){    // if  leaf node insert that string into pq
        reverse(str.begin(),str.end());
            pq.push(str);
            return;
        }
        dfs(root->left,str);
        dfs(root->right,str);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        dfs(root,"");
        string res=pq.top(); // return minimum string from priority queue
        
        return res;
    }
};