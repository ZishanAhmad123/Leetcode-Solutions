
class Solution {
public:
    TreeNode *dfs(vector<int> &nums, int lo, int hi) {
        if(lo > hi) return NULL;
        int  maxi = -1, maxIndex;
        for( int i=lo;i<=hi;i++) {
            if(maxi < nums[i]) {
                maxi = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode (nums[maxIndex]);  // just as construct bst from a sorted vector
        root->left = dfs(nums, lo, maxIndex-1);
        root->right = dfs(nums, maxIndex+1, hi);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int n = a.size(), lo=0, hi = n-1;
        return dfs(a, lo, hi);
    }
};