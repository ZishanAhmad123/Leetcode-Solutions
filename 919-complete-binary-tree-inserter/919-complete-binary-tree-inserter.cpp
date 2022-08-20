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
class CBTInserter {
public:
    TreeNode *tree;
    queue<TreeNode*> level;
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            auto node = Q.front();
            level.push(node);
            Q.pop();
            if (node->left) {
                Q.push(node->left);
            }
            if (node->right) {
                Q.push(node->right);
            }
        }
        tree = root;
    }
    
    int insert(int val) {
        int par = -1;
        TreeNode *t = new TreeNode(val);
        while(level.size() > 0) {
            auto node = level.front();
            if (node->left && node->right) {
                level.pop();
                continue;
            } else if (node->left == NULL) {
                par = node->val;
                node->left = t;
            } else if (node->right == NULL) {
                par = node->val;
                node->right = t;
            }
            level.push(t);
            break;
        }
        return par;
    }
    
    TreeNode* get_root() {
        return tree;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */