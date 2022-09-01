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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
         if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
             vector<int>v;
            int size=q.size();
            
            for(int i=0; i<size; i++){
            TreeNode* cur =q.front();
              q.pop();
            v.push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right)
                q.push(cur->right);
        }
         ans.push_back(v);
        v.clear();
       }  
        return ans;
    }
        
    bool increasingOdd(vector<int> v){
        if(v[0]%2 == 0){
            return false;
        }
        for(int i = 1; i<v.size();i++){
            if(v[i]%2 != 0){
                if(v[i-1] >= v[i]){
                    return false;
                } 
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool DecreasingEven(vector<int> v){
        if(v[0]%2 != 0){
            return false;
        }
        for(int i = 1; i<v.size();i++){
            if(v[i]%2 == 0){
                if(v[i-1] <= v[i]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> vec = levelOrder(root);
        int level = 0;
        for(auto v : vec){
            if(level %2 == 0){
                if(!increasingOdd(v)){
                    return false;
                }
            }
            if(level %2 != 0){
                if(!DecreasingEven(v)){
                    return false;
                }
            }
            level++;
        }
        return true;
    }
};