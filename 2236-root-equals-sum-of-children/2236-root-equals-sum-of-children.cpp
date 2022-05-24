/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int inOrder(TreeNode *root, int &sum)
        {
            if (!root) return 0;

            inOrder(root->left, sum);
            sum += root->val;
           inOrder(root->right, sum);

            return sum;
        }

    bool checkTree(TreeNode *root)
    {
        int sum = 0;
        sum = inOrder(root, sum) - root->val;

        if (sum == root->val) return true;
        return false;
    }
};