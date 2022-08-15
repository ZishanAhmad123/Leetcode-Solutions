class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> myvec;
        if(root==NULL){
            return myvec;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            myvec.push_back(level);
            level.clear();
        }
        return myvec;
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> myvec = levelOrder(root);
        vector<int> ans = myvec[myvec.size()-1];    // last vector is our ans
        return accumulate(ans.begin(),ans.end(),0);
    }
};