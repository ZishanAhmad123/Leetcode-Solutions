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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>v;
        while(!q.empty()){
            double sum=0;int cnt=0;
            double avg;
            int sz=q.size();
            for(int i=0;i <sz; i++){
               TreeNode* front=q.front();
                q.pop();
                sum+=front->val;
                cnt++;
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            avg=sum/cnt;
            v.push_back(avg);
        }
        return v;
    }
};